/**
 * @file
 * @author Ceyhun Şen
 * @brief Test file for Housement firmware.
 * */

#include "state_machine.h"
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
}

void test_event_seg_fault()
{
	sm.run();
	sm.add_event(ev_burglar_alarm);
	sm.run();
}

int main()
{
	RUN_TEST(test_construction);
	RUN_TEST(test_event_seg_fault);
	return (UnityEnd());
}
