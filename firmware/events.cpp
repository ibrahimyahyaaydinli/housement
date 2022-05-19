/**
 * @file
 * @author Ceyhun Şen
 * @brief Event functions for Housement firmware.
 * */

#include "events.h"
#include "state_machine.h"
#include "housement_server.h"

housement_server h_server;

#ifdef ARDUINO

#include <Arduino.h>
#include <Adafruit_BMP280.h>

// Extern BMP280 object.
extern Adafruit_BMP280 bmp280;

#endif // ARDUINO

static void burglar_alarm();
static void extreme_temperature();
static void read_temperature();
static void (*state_functions[])() = {burglar_alarm, extreme_temperature, read_temperature};

void run_event(events event)
{
	state_functions[event]();
}

void burglar_alarm()
{
}

void extreme_temperature()
{
}

/**
 * @brief Read temperature based on event.
 * */
void read_temperature()
{
	h_server.send_temperature(bmp280.readTemperature());
}
