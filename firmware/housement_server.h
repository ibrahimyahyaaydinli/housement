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
		void init();
		void send_temperature(float temperature);
};

#endif // __SERVER_H
