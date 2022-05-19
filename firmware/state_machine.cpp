/**
 * @file
 * @author Ceyhun Şen
 * @brief State machine functions for Housement firmware.
 * */

#include "state_machine.h"

static void burglar_alarm();
static void extreme_temperature();
static void (*state_functions[])() = {burglar_alarm, extreme_temperature};

housement_state_machine::housement_state_machine()
{
	state = idle;
}

void housement_state_machine::run()
{
	// If no event is queued, return.
	if (event_queue.empty()) {
		return;
	}

	// Get next event.
	events next_event = event_queue.front();
	event_queue.pop();

	// Run event function.
	state_functions[next_event]();
}

void housement_state_machine::add_event(events event)
{
	event_queue.push(event);
}

states housement_state_machine::get_state()
{
	return state;
}

/*******************************************************************************
 * State functions.
 ******************************************************************************/
void burglar_alarm()
{
}

void extreme_temperature()
{
}
