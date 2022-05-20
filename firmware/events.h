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
	ev_read_temperature = 0,
	ev_read_gas,
	ev_read_movement,
	ev_update_database,
	ev_burglar_alarm,
	ev_extreme_temperature,
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
