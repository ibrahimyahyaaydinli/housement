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

static void read_sensor();
static void read_movement();
static void update_database();
static void burglar_alarm();
static void extreme_temperature();
static void open_led();
static void close_led();
static void (*state_functions[])() = {read_sensor, read_movement, update_database, burglar_alarm, extreme_temperature, open_led, close_led};

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
	h_server.temperature = bme680.temperature;
	debug_println("Temperature: " + (String)h_server.temperature);

	// Check extreme temperature.
	if (h_server.temperature >= h_server.extreme_temperature) {
		state_machine.add_event(ev_extreme_temperature);
	}

	// Get gas resistance.
	h_server.gas = bme680.gas_resistance / 1000.0;
	debug_println("Gas resistance: " + (String)h_server.gas);
}

static void read_movement()
{
	if (digitalRead(pir_sensor) == HIGH) {
		state_machine.add_event(ev_burglar_alarm);
	}
}

static void update_database()
{
	h_server.send_database();
	h_server.get_database();
}

static void burglar_alarm()
{
	if (state_machine.get_state() == alarm_active) {
		digitalWrite(buzzer, HIGH);
		h_server.movement_detected = true;
	}
	else {
		digitalWrite(buzzer, LOW);
		h_server.movement_detected = false;
		state_machine.state = reading;
	}
	debug_println("Burglar alarm!");
}

static void extreme_temperature()
{
	digitalWrite(buzzer, HIGH);
	debug_println("Extreme temperature!");
}

static void open_led()
{
	digitalWrite(led, HIGH);
	debug_println("Led opened.");
}

static void close_led()
{
	digitalWrite(led, LOW);
	debug_println("Led closed.");
}
