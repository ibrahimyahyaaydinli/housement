/**
 * @file
 * @author Ceyhun Şen
 * @brief Main source file for Arduino Core.
 * */

#include "housement.h"
#include "state_machine.h"
#include "housement_server.h"
#include <WiFi.h>
#include <Adafruit_BME680.h>
#include <Firebase_ESP_Client.h>

/*******************************************************************************
 * Global variables.
 ******************************************************************************/

// State machine object.
housement_state_machine state_machine;

// Wi-Fi credentials.
const char *ssid     = "";
const char *password = "";

// BME680 object.
Adafruit_BME680 bme680;

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

	// Initialize BMP680.
	if (!bme680.begin()) {
		debug_println("BME680 not found! Check wiring!");
		while (1);
	}

	// Set up oversampling and filter initialization
	bme680.setTemperatureOversampling(BME680_OS_1X);
	bme680.setHumidityOversampling(BME680_OS_1X);
	bme680.setPressureOversampling(BME680_OS_1X);
	bme680.setIIRFilterSize(BME680_FILTER_SIZE_1);
	bme680.setGasHeater(100, 10); // 100*C for 10 ms

	// Start Firebase.
	housement_server_init();

	// Set buzzer as output.
	pinMode(buzzer, OUTPUT);

	// Set pir as input.
	pinMode(pir_sensor, INPUT);

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
