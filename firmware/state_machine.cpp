/**
 * @file
 * @author Ceyhun Şen
 * @brief State machine functions for Housement firmware.
 * */

#include "state_machine.h"
#include "events.h"
#include <mutex>

std::mutex mtx;

/**
 * @brief State machine class contructor.
 * */
housement_state_machine::housement_state_machine()
{
	this->state = reading;
	this->clock = 0;
}

/**
 * @brief Execute next function based on next event.
 * */
void housement_state_machine::run()
{
	add_timer_events();

	// If no event is queued, return.
	if (this->event_queue.empty()) {
		return;
	}

	// Get next event.
	events next_event = event_queue.front();
	event_queue.pop();

	// Run event function.
	run_event(next_event);
}

/**
 * @brief Add new event to the event queue.
 * */
void housement_state_machine::add_event(events event)
{
	mtx.lock();
	if (event_queue.size() <= MAX_QUEUE_SIZE)
		event_queue.push(event);
	mtx.unlock();
}

/**
 * @brief Update clock (milliseconds). Should be called every 10 ms.
 * */
void housement_state_machine::update_clock()
{
	// Add 10 millisecond.
	this->clock += 10;

	// Reset every 10 seconds.
	this->clock %= 10000;
}

/**
 * @brief Getter function for state variable.
 * @returns Current state.
 * */
states housement_state_machine::get_state()
{
	return state;
}

/**
 * @brief Getter function for clock variable.
 * @returns Current clock in milliseconds.
 * */
uint16_t housement_state_machine::get_clock()
{
	return clock;
}

/**
 * @brief Add events to event queue based on timer.
 * */
void housement_state_machine::add_timer_events()
{
	// Read temperature every 100 ms.
	static uint16_t last_temperature_read = 0;
	if (this->clock % 100 == 0 && last_temperature_read != this->clock) {
		last_temperature_read = this->clock;
		this->add_event(ev_read_temperature);
	}

	// Read gas every 500 ms.
	static uint16_t last_gas_read = 0;
	if (this->clock % 500 == 0 && last_gas_read != this->clock) {
		last_gas_read = this->clock;
		this->add_event(ev_read_gas);
	}

	// Update database every 1000 ms.
	static uint16_t last_database_update = 0;
	if (this->clock % 1000 == 0 && last_database_update != this->clock) {
		last_database_update = this->clock;
		this->add_event(ev_update_database);
	}
}
