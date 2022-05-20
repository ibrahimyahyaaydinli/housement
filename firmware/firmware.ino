/**
 * @file
 * @author Ceyhun Şen
 * @brief Main source file for Arduino Core.
 * */

#include "housement.h"
#include "state_machine.h"
#include "housement_server.h"
#include <WiFi.h>
#include <Adafruit_BMP280.h>
#include <Firebase_ESP_Client.h>

/*******************************************************************************
 * Global variables.
 ******************************************************************************/

// State machine object.
housement_state_machine state_machine;

// Wi-Fi credentials.
const char *ssid     = "";
const char *password = "";

// BMP280 object.
Adafruit_BMP280 bmp280;

/*******************************************************************************
 * 10 ms timer.
 ******************************************************************************/
hw_timer_t *timer = NULL;
volatile SemaphoreHandle_t timerSemaphore;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void ARDUINO_ISR_ATTR timer_10ms()
{
	portENTER_CRITICAL_ISR(&timerMux);

	state_machine.update_clock();

	portEXIT_CRITICAL_ISR(&timerMux);
}

/*******************************************************************************
 * Functions.
 ******************************************************************************/
/**
 * @brief Setup function for Arduino Core.
 * */
void setup()
{
	#ifdef H_DEBUG
	// Start serial communication over UART.
	Serial.begin(115200);
	#endif // H_DEBUG

	// Start connecting Wi-Fi.
	debug_print("Wi-fi connecting to: ");
	debug_println(ssid);
	WiFi.begin(ssid, password);

	// Wait for connection.
	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
		debug_print(".");
	}

	debug_println("\nWi-Fi connected successfully!");
	debug_print("Local IP address is: ");
	debug_println(WiFi.localIP());

	// Initialize BMP280.
	if (!bmp280.begin()) {
		debug_println("BMP280 not found! Check wiring!");
		while (1);
	}

	// Configure BMP280.
	bmp280.setSampling(Adafruit_BMP280::MODE_NORMAL,
	                   Adafruit_BMP280::SAMPLING_X2,
	                   Adafruit_BMP280::SAMPLING_X16,
	                   Adafruit_BMP280::FILTER_X16,
	                   Adafruit_BMP280::STANDBY_MS_500);

	// Start Firebase.
	housement_server_init();

	// Set buzzer as output.
	pinMode(buzzer, HIGH);

    // Configure timer in 10 ms.
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &timer_10ms, true);
    timerAlarmWrite(timer, 10000, true);
    timerAlarmEnable(timer);
}

/**
 * @brief Loop function for Arduino Core.
 * */
void loop()
{
	state_machine.run();
}
