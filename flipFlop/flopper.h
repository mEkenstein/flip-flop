#ifndef FLOPPER_H
#define FLOPPER_H

// Class that is used to describe the state and behaviour of the blue floppers.
// Similar to a tree structure, every flopper has two children, one to the left and one to the right, 
// and depending on the current state of the flopper, we decide which flopper is next for a given ball.
class flopper {

private: 	

	enum State { openLeft, openRight }; //0 for open to the left, 1 for right
	State state = openLeft;

public: 
	flopper(flopper* tl, flopper* tr); // Constructor with pointers to left and right floppers

	flopper* left; // Address to left flopper
	flopper* right; //Address to right flopper

	void switchState();
	State getState();
};


#endif //FLOPPER_H

