// Created for Mon 4/10/17
// By Victoria Albanese and Tim Larocque
// Project Checkpoint 1


#include <stdio.h>

#define LANCE 1
#define SHIELD 8

#define RHAT 0
#define LHAT 1

#define RMOTOR 0
#define LMOTOR 3

void collisionDetection();
void avoid_border_left();
void avoid_border_right();

int main() 
{
	// enable floating analog ports
	enable_servos();
	set_each_analog_state(0,0,0,0,0,0,0,0); 
	
	// do this forever...
	while(!black_button()) {		
		
		// print stuff
		printf("Right top hat: %d\n", analog10(RHAT));
		printf("Left top hat:  %d\n", analog10(LHAT));
		
		// keep moving forward
		mav(LMOTOR, 300);
		mav(RMOTOR, 300);
		
		// if black is detected on left side, veer right
		if (analog10(LHAT) > 500) { 
			avoid_border_left();
		} 
		
		// if black is detected on right side, veer left
		if (analog10(RHAT) > 500) { 
			avoid_border_right();
		}
				
	}	
	
	return 0;
}

// not yet working
void collisionDetection() {
	
	if(digital(SHIELD)) {
		
		while(1) {
			ao();
			msleep(50);
			mav(LMOTOR, -800);
			mav(RMOTOR, 800);
		}
		
	}
	
}

void avoid_border_left() {
	
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);

	bmd(LMOTOR);
	bmd(RMOTOR);

	mrp(LMOTOR, 500, 400); 
	bmd(LMOTOR);
		
	return;
	
}

void avoid_border_right() {
	
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);

	bmd(LMOTOR);
	bmd(RMOTOR);
			
	mrp(RMOTOR, 500, 400); 
	bmd(RMOTOR);
		
	return;
	
}
