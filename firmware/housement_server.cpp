/**
 * @file
 * @author Ceyhun Şen
 * @brief Server functions for Housement firmware.
 * */

#include "housement.h"
#include "housement_server.h"
#include "state_machine.h"
#include <Arduino.h>
#include <Firebase_ESP_Client.h>

extern housement_state_machine state_machine;

// Firebase credentials.
static const char *firebase_host = "";
static const char *firebase_api_key = "";

// Firebase data objects.
static FirebaseData fbdo;
static FirebaseAuth auth;
static FirebaseConfig config;

void housement_server_init()
{
	config.api_key = firebase_api_key;
	config.database_url = firebase_host;

	debug_println("Trying to connect Firebase.");
	while (1) {
		if (Firebase.signUp(&config, &auth, "", "")) {
			debug_println("\nConnected to Firebase");
			break;
		}
		debug_print(".");
		delay(100);
	}

	Firebase.begin(&config, &auth);
	Firebase.reconnectWiFi(true);

	Firebase.RTDB.setMaxRetry(&fbdo, 1);
}

void housement_server::send_database()
{
	debug_println("Sending to database.");
	if (Firebase.ready()) {
		if (!Firebase.RTDB.setFloatAsync(&fbdo, "sensor_values/temperature", this->temperature))
			debug_println("Error: " + fbdo.errorReason());
		if (!Firebase.RTDB.setFloatAsync(&fbdo, "sensor_values/gas", this->gas))
			debug_println("Error: " + fbdo.errorReason());
		if (!Firebase.RTDB.setBoolAsync(&fbdo, "sensor_values/movement_detected", this->movement_detected))
			debug_println("Error: " + fbdo.errorReason());
	}
	else {
		debug_println("Firebase is not ready!");
	}
	debug_println("Saved data to Firebase.");
}

void housement_server::get_database()
{
	debug_println("Getting data from database.");
	if (Firebase.ready()) {
		if (Firebase.RTDB.getBool(&fbdo, "sensor_values/is_away"))
			if (fbdo.dataTypeEnum() == fb_esp_rtdb_data_type_boolean) {
				bool is_away = fbdo.to<bool>();
				if (is_away) {
					state_machine.state = alarm_active;
				}
				else {
					state_machine.state = reading;
				}
			}
	}
	else {
		debug_println("Firebase is not ready!");
	}
	debug_println("Saved data from Firebase.");
}
