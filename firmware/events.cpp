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
#include <Adafruit_BMP280.h>

housement_server h_server;

// Extern state machine object.
extern housement_state_machine state_machine;

// Extern BMP280 object.
extern Adafruit_BMP280 bmp280;

static void read_temperature();
static void read_gas();
static void read_movement();
static void update_database();
static void burglar_alarm();
static void extreme_temperature();
static void (*state_functions[])() = {read_temperature, read_gas, read_movement, update_database, burglar_alarm, extreme_temperature};

void run_event(events event)
{
	state_functions[event]();
}

/**
 * @brief Read temperature based on event.
 * */
void read_temperature()
{
	h_server.temperature = bmp280.readTemperature();
	debug_println("Temperature: " + (String)h_server.temperature);

	// Check extreme temperature.
	if (h_server.temperature >= h_server.extreme_temperature) {
		state_machine.add_event(ev_extreme_temperature);
	}
}

static void read_gas()
{
	
}

static void read_movement()
{
	
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
