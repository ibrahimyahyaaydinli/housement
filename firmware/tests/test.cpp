/**
 * @file
 * @author Ceyhun Şen
 * @brief Test file for Housement firmware.
 * */

#include "state_machine.h"
#include "events.h"
#include "unity.h"
#include <iostream>
#include <assert.h>

using namespace std;

// Create state machine object.
housement_state_machine sm;

void setUp()
{
	
}

void tearDown()
{
	
}

void test_construction()
{
	TEST_ASSERT_EQUAL(sm.get_state(), idle);
	TEST_ASSERT_EQUAL(sm.get_clock(), 0);
}

void test_event_seg_fault()
{
	sm.run();
	sm.add_event(ev_burglar_alarm);
	sm.run();
}

void test_temperature_read()
{
	sm.run();
}

void test_clock()
{
	sm.update_clock();
	TEST_ASSERT_EQUAL(sm.get_clock(), 10);
}

int main()
{
	RUN_TEST(test_construction);
	RUN_TEST(test_event_seg_fault);
	RUN_TEST(test_temperature_read);
	RUN_TEST(test_clock);
	return (UnityEnd());
}
