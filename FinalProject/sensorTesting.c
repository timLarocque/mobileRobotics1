#include <stdio.h>

#define LANCE 1
#define SHIELD 8

#define RHAT 0
#define LHAT 1

#define RMOTOR 0
#define LMOTOR 3

void collisionDetection();

int main() 
{
	// enable floating analog ports
	enable_servos();
	set_each_analog_state(1,1,1,1,1,1,1,1); 
	
	// do this forever...
	while(!black_button()) {		
		
		// print stuff
		printf("Right top hat: %d\n", RHAT);
		printf("Left top hat:  %d\n", LHAT);
		
		collisionDetection();
		
		// if black is detected on left side, veer right
		while (analog10(LHAT) > 500) { 
			mav(LMOTOR, 800);
			mav(RMOTOR, -800);
		} 
		
		// if black is detected on right side, veer left
		while (analog10(RHAT) > 500) { 
			mav(RMOTOR, 800);
			mav(LMOTOR, -800);
		}
		
		// keep moving forward
		mav(LMOTOR, 300);
		mav(RMOTOR, 300);
				
	}	
}

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
