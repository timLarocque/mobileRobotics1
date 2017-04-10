#include <stdio.h>

#define LANCE 1
#define SHIELD 8

#define RHAT 0
#define LHAT 1

#define RMOTOR 0
#define LMOTOR 3

int main() 
{
	enable_servos();
	set_each_analog_state(1,0,0,0,0,0,0,0); // enable floating analog port for port 0
	
	while(!black_button()) {
		// keep moving forward
		mav(LMOTOR, 300);
		mav(RMOTOR, 300);
			
		// if black is detected on right side
		if (analog10(RHAT) > 500) {
			
			// turn left a little
			mav(RMOTOR, 300);
			mav(LMOTOR, 100);
		
		}
			
		// if black is detected on left side
		if (analog10(LHAT) > 500) {
		
			// turn right a little
			mav(LMOTOR, 300);
			mav(RMOTOR, 100);
		}
	}	
}
