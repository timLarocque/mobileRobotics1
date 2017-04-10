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
	enable_servos();
	set_each_analog_state(1,0,0,0,0,0,0,0); // enable floating analog port for port 0
	
	while(!black_button()) {		
		collisionDetection();
		if (analog10(LHAT) > 500) { // if black is detected on left side
			// turn right a little
			mav(LMOTOR, 800);
			mav(RMOTOR, -800);
		} else if (analog10(RHAT) > 500) { // if black is detected on right side
			// turn left a little
			mav(RMOTOR, 800);
			mav(LMOTOR, -800);
		}else {
			// keep moving forward
			mav(LMOTOR, 300);
			mav(RMOTOR, 300);
		}
		printf("Right top hat: %d\n", RHAT);
		printf("Left top hat:  %d\n", LHAT);
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
