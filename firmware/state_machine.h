/**
 * @file
 * @author Ceyhun Şen
 * @brief State machine header for Housement firmware.
 * */

#ifndef __STATE_MACHINE_H
#define __STATE_MACHINE_H

#include <queue>

/**
 * @brief Events for the state machine.
 * */
typedef enum events {
	ev_burglar_alarm = 0,
	ev_extreme_temperature
} events;

/**
 * @brief State machine states.
 * */
typedef enum states {
	idle = 0,
	read_temperature,
	alarm
} states;

/**
 * @brief State machine class.
 * */
class housement_state_machine {
	public:
		housement_state_machine();
		void run();
		void add_event(events event);
		states get_state();

	private:
		states state;
		std::queue<events> event_queue;
};

#endif // __STATE_MACHINE_H
