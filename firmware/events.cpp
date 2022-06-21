/**
 * @file
 * @author Ceyhun Şen
 * @brief Event functions for Housement firmware.
 * */

#include "events.h"
#include "state_machine.h"
#include "housement_server.h"
#include "housement.h"
#include <Arduino.h>
#include <Adafruit_BME680.h>

housement_server h_server;

// Extern state machine object.
extern housement_state_machine state_machine;

// Extern BMP280 object.
extern Adafruit_BME680 bme680;

// Extern burglar alarm irq bool.
extern bool is_movement;

static void read_sensor();
static void read_movement();
static void update_database();
static void burglar_alarm();
static void extreme_temperature();
static void open_led1();
static void close_led1();
static void open_led2();
static void close_led2();
static void (*state_functions[])() = {read_sensor, read_movement, update_database, burglar_alarm, extreme_temperature, open_led1, close_led1, open_led2, close_led2};

void run_event(events event)
{
	state_functions[event]();
}

/**
 * @brief Read sensor data.
 * */
void read_sensor()
{
	// Get temperature.
	if (!bme680.performReading()) {
		debug_println("Error on reading sensor data!");
		exit(1);
	}
	float temp_temperature = (int32_t)(bme680.temperature * 10 + 0.5);
	h_server.temperature = (float)temp_temperature / 10;
	debug_println("Temperature: " + (String)h_server.temperature);

	// Check extreme temperature.
	if (h_server.temperature >= h_server.extreme_temperature) {
		state_machine.add_event(ev_extreme_temperature);
	}

	// Get gas resistance.
	float temp_gas = (int32_t)(bme680.gas_resistance * 10 + 0.5);
	h_server.gas = (float)temp_gas / 10 / 1000.0;
	debug_println("Gas resistance: " + (String)h_server.gas);
}

static void read_movement()
{
	if (is_movement) {
		state_machine.add_event(ev_burglar_alarm);
	}
	is_movement = false;
}

static void update_database()
{
	h_server.send_database();
	h_server.get_database();
}

static void burglar_alarm()
{
	if (state_machine.get_state() == alarm_active) {
		debug_println("Burglar alarm!");
		digitalWrite(buzzer, HIGH);
		h_server.movement_detected = true;
	}
	else {
		debug_println("Movement.");
		digitalWrite(buzzer, LOW);
		h_server.movement_detected = false;
		state_machine.state = reading;
	}
}

static void extreme_temperature()
{
	digitalWrite(buzzer, HIGH);
	debug_println("Extreme temperature!");
}

static void open_led1()
{
	digitalWrite(led1, HIGH);
	debug_println("Led 1 opened.");
}

static void close_led1()
{
	digitalWrite(led1, LOW);
	debug_println("Led 1 closed.");
}

static void open_led2()
{
	digitalWrite(led2, HIGH);
	debug_println("Led 2 opened.");
}

static void close_led2()
{
	digitalWrite(led2, LOW);
	debug_println("Led 2 closed.");
}
