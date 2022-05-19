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
	ev_burglar_alarm = 0,
	ev_extreme_temperature,
	ev_read_temperature,
} events;

/**
 * @brief State machine states.
 * */
typedef enum states {
	idle = 0,
	reading,
	alarm_active
} states;

void run_event(events event);

#endif // __EVENTS_H
