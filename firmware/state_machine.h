/**
 * @file
 * @author Ceyhun Şen
 * @brief State machine header for Housement firmware.
 * */

#ifndef __STATE_MACHINE_H
#define __STATE_MACHINE_H

#include "events.h"
#include <queue>
#include <cstdint>

/**
 * @brief State machine class.
 * */
class housement_state_machine {
	public:
		housement_state_machine();
		void run();
		void add_event(events event);
		void update_clock();
		states get_state();
		uint16_t get_clock();

	private:
		states state;
		std::queue<events> event_queue;
		volatile uint16_t clock;
		void add_timer_events();
};

#endif // __STATE_MACHINE_H
