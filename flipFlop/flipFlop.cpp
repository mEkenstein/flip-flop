#include "pch.h"
#include <iostream>
#include "flopper.h"

/* This program solves the Mystery Geocache Flip-Flop: https://www.geocaching.com/seek/cache_details.aspx?wp=GC25BJH&title=flip-flop 
	Written by Mattias Ekström */

int main()
{
	// Create the queue of balls
	int balls[68] = { 5, 2, 1, 7, 9, 2, 8, 6, 3, 4,
					0, 5, 1, 3, 8, 8, 10, 6, 6,
					2, 1, 2, 1, 4, 3, 8, 5, 8, 6,
					9, 10, 1, 3, 4, 5, 2, 2, 4, 8,
					9, 6, 10, 8, 4, 6, 1, 5, 3, 2,
					5, 10, 8, 6, 8, 1, 9, 4, 4, 1,
					7, 3, 2, 7, 6, 10, 9, 3, 5 };

	/* Initialize the flip-floppers.
	Letters are levels, numbers are rows.
	Start from bottom left.
	Constructed with pointers to the flopper to the left and to the right, respectively.
	NULL means that a ball is going to hit a bucket after the current flopper. */

	flopper A1(NULL, NULL);

	flopper B1(NULL, NULL);
	flopper B2(NULL, &A1);
	flopper B3(&A1, NULL);
	flopper B4(NULL, NULL);

	flopper C1(&B1, NULL);
	flopper C2(NULL, &B2);
	flopper C3(&B3, NULL);
	flopper C4(NULL, &B4);

	flopper D1(&C1, NULL);
	flopper D2(NULL, &C2);
	flopper D3(&C2, &A1);
	flopper D4(&A1, &C3);
	flopper D5(&C3, NULL);
	flopper D6(NULL, &C4);

	flopper E1(&D1, &D2);
	flopper E2(&D3, &D4);
	flopper E3(&D5, &D6);

	flopper F1(&E1, &E2);
	flopper F2(&E2, &E3);

	flopper G1(&F1, &F2);

	// Initialize to 0 balls in every bucket
	int bucketTick[14] = { 0 };

	// -1 means that a number has not been assigned to the letter.
	int A = -1;
	int B = -1;
	int C = -1;
	int D = -1;
	int E = -1;
	int F = -1;
	int G = -1;
	int H = -1;
	int I = -1;
	int J = -1;
	int K = -1;
	int L = -1;
	int M = -1;
	int N = -1;
	int O = -1;


	/* Main loop for placing the balls in the bottom buckets.
	NULL pointer means a bucket has been hit */

	for (int i = 0; i < 68; i++) {
		
		//G1 är den första floppern på kartan
		flopper* curPtr = &G1;
		flopper* prevPtr = &G1;
		while (curPtr != NULL) {

			//If the current pointer is open to the left, set pointer to left flopper as next in loop
			if (curPtr->getState() == 0) {
				prevPtr = curPtr;
				curPtr->switchState();				
				curPtr = curPtr->left;
			}
			// Same for the right
			else {
				prevPtr = curPtr;
				curPtr->switchState();				
				curPtr = curPtr->right;
			}
		}

		// Here we evaluate the last node and decide which bucket is hit.
		// Note that the logic is reversed since the flopper pointed to by prevPtr was flipped after being stored
		

		if (prevPtr == &A1) {
			if (prevPtr->getState() == 1) {
				bucketTick[6]++;				
			}
			else {
				bucketTick[7]++;				
			}
		}
		else if (prevPtr == &B1) {
			if (prevPtr->getState() == 1) {
				bucketTick[0]++;				
			}
			else {
				bucketTick[1]++;				
			}
		}
		else if (prevPtr == &B2 && prevPtr->getState() == 1) {
			bucketTick[5]++;			
		}
		else if (prevPtr == &B3 && prevPtr->getState() == 0) {
			bucketTick[8]++;			
		}
		else if (prevPtr == &B4) {
			if (prevPtr->getState() == 1) {
				bucketTick[12]++;				
			}
			else {
				bucketTick[13]++;				
			}
		}
		else if (prevPtr == &C1 && prevPtr->getState() == 0) {
			bucketTick[2]++;			
		}
		else if (prevPtr == &C2 && prevPtr->getState() == 1) {
			bucketTick[4]++;			
		}
		else if (prevPtr == &C3 && prevPtr->getState() == 0) {
			bucketTick[9]++;			
		}
		else if (prevPtr == &C4 && prevPtr->getState() == 1) {
			bucketTick[11]++;			
		}
		else if (prevPtr == &D1 && prevPtr->getState() == 0) {
			bucketTick[3]++;			
		}
		else if (prevPtr == &D2 && prevPtr->getState() == 1) {
			bucketTick[3]++;			
		}
		else if (prevPtr == &D5 && prevPtr->getState() == 0) {
			bucketTick[10]++;			
		}
		else if (prevPtr == &D6 && prevPtr->getState() == 1) {
			bucketTick[10]++;			
		}

		// Assign the correct letter to the ball numbers.
		if (bucketTick[0] == 1 && A == -1) {
			A = balls[i];			
		}
		else if (bucketTick[3] == 1 && B == -1) {
			B = balls[i];			
		}
		else if (bucketTick[6] == 1 && I == -1) {
			I = balls[i];			
		}
		else if (bucketTick[10] == 1 && J == -1) {
			J = balls[i];			
		}
		else if (bucketTick[7] == 2 && H == -1) {
			H = balls[i];			
		}
		else if (bucketTick[11] == 2 && K == -1) {
			K = balls[i];			
		}
		else if (bucketTick[6] == 3 && C == -1) {
			C = balls[i];			
		}
		else if (bucketTick[7] == 6 && L == -1) {
			L = balls[i];			
		}
		else if (bucketTick[6] == 7 && G == -1) {
			G = balls[i];			
		}
		else if (bucketTick[9] == 6 && D == -1) {
			D = balls[i];			
		}
		else if (bucketTick[10] == 7 && E == -1) {
			E = balls[i];			
		}
		else if (bucketTick[4] == 7 && O == -1) {
			O = balls[i];			
		}
		else if (bucketTick[5] == 3 && M == -1) {
			M = balls[i];			
		}
		else if (bucketTick[7] == 12 && N == -1) {
			N = balls[i];			
		}
		else if (bucketTick[10] == 8 && F == -1) {
			F = balls[i];			
		}
	}

	// Print out the coordinates
	std::cout << "---  The coordinates are  ---" << std::endl;
	std::cout << "North " << A << B << " " << C << D << "." << E << F << G << std::endl;
	std::cout << "East " << H << I << J << " " << K << L << "." << M << N << O << std::endl;
	std::cin.get();

	return 0;
}

