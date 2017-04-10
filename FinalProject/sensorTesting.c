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
	
	// keep moving forward
	mrp(0, 200, -50);
	mrp(3, 200, 50);
		
	// if black is detected on right side
	if (analog10(RMOTOR) > 500) {
		
		// turn left a little
		mrp(0, 300, 50); 
		mrp(3, 250, 50);
	
	}
		
	// if black is detected on left side
	if (analog10(LMOTOR) > 500) {
	
		// turn right a little
		mrp(0, 300, -50); 
		mrp(3, 250, -50);
		
	}	
}
