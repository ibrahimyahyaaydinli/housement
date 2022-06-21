/**
 * @file
 * @author Ceyhun Şen
 * @brief Event header for Housement firmware.
 * */

#ifndef __EVENTS_H
#define __EVENTS_H

/**
 * @brief Events for the state machine.
 * */
typedef enum events {
	ev_read_sensor = 0,
	ev_read_movement,
	ev_update_database,
	ev_burglar_alarm,
	ev_extreme_temperature,
	ev_open_led1,
	ev_close_led1,
	ev_open_led2,
	ev_close_led2
} events;

/**
 * @brief State machine states.
 * */
typedef enum states {
	reading = 0,
	alarm_active
} states;

void run_event(events event);

#endif // __EVENTS_H
