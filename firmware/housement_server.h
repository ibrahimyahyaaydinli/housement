/**
 * @file
 * @author Ceyhun Şen
 * @brief Server header for Housement firmware.
 * */

#ifndef __SERVER_H
#define __SERVER_H

void housement_server_init();

class housement_server {
	public:
		float temperature;
		float extreme_temperature;
		float gas;
		bool movement_detected;
		bool is_away;
		housement_server()
		{
			temperature = 0.0;
			extreme_temperature = 40.0;
			gas = 0.0;
			movement_detected = false;
			is_away = false;
		}
		void init();
		void send_database();
		void get_database();
};

#endif // __SERVER_H
