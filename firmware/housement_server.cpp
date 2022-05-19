/**
 * @file
 * @author Ceyhun Şen
 * @brief Server functions for Housement firmware.
 * */

#include "housement_server.h"
#include <Arduino.h>
#include <Firebase_ESP_Client.h>

// Firebase credentials.
static const char *firebase_host = "relace with host address";
static const char *firebase_api_key = "replace with api key";

// Firebase data objects.
static FirebaseData fbdo;
static FirebaseAuth auth;
static FirebaseConfig config;

void housement_server_init()
{
	config.api_key = firebase_api_key;
	config.database_url = firebase_host;

	Serial.println("Trying to connect Firebase.");
	while (1) {
		if (Firebase.signUp(&config, &auth, "", "")) {
			Serial.println("\nConnected to Firebase");
			break;
		}
		Serial.print(".");
		delay(100);
	}

	Firebase.begin(&config, &auth);
	Firebase.reconnectWiFi(true);
}

void housement_server::send_temperature(float temperature)
{
	Serial.println(temperature);
	if (Firebase.ready()) {
		if (Firebase.RTDB.setFloat(&fbdo, "temperature", temperature)) {
			Serial.println("PASSED");
			Serial.println("PATH: " + fbdo.dataPath());
			Serial.println("TYPE: " + fbdo.dataType());
		}
		else {
			Serial.println("FAILED");
			Serial.println("REASON: " + fbdo.errorReason());
		}
	}
}
