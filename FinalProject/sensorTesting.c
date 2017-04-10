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
	
}
