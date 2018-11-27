#include "pch.h"
#include "flopper.h"
#include <iostream>
// Constructor with pointers to left and right flopper
flopper::flopper(flopper* tl, flopper* tr)
: left(tl), right(tr) {	}

// Switch the state of the flopper
void flopper::switchState() {
	if (state == openLeft) {
		state = openRight;
	}
	else {
		state = openLeft;
	}
}
//  Return the current state.
flopper::State flopper::getState() {
	return state;
}