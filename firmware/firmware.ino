/**
 * @file firmware.ino
 * @author Ceyhun Şen
 * */

#include "state_machine.h"
#include <WiFi.h>
#include <Adafruit_BMP280.h>

// Wi-Fi credentials.
const char* ssid     = "jiyuns-a20";
const char* password = "ourm74rmqk";

// BMP280 object;
Adafruit_BMP280 bmp280;

/**
 * @brief Setup function for Arduino Core.
 * */
void setup()
{
	// Start serial communication over UART.
	Serial.begin(115200);

	// Start connecting Wi-Fi.
	Serial.print("Wi-fi connecting to: ");
	Serial.println(ssid);
	WiFi.begin(ssid, password);

	// Wait for connection.
	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
		Serial.print(".");
	}

	Serial.println("\nWi-Fi connected successfully!");
	Serial.print("Local IP address is: ");
	Serial.println(WiFi.localIP());

	// Initialize BMP280.
	if (!bmp280.begin()) {
		Serial.println("BMP280 not found! Check wiring!");
		while (1);
	}

	// Configure BMP280.
	bmp280.setSampling(Adafruit_BMP280::MODE_NORMAL,
                       Adafruit_BMP280::SAMPLING_X2,
                       Adafruit_BMP280::SAMPLING_X16,
                       Adafruit_BMP280::FILTER_X16,
                       Adafruit_BMP280::STANDBY_MS_500);
}

/**
 * @brief Loop function for Arduino Core.
 * */
void loop()
{
	Serial.println(bmp280.readTemperature());
	housement_state_machine sm;
	delay(1000);
}
