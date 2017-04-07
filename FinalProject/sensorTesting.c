#include <stdio.h>

#define LANCE 1
#define SHIELD 8

#define LHAT 0
#define RHAT 1

#define RMOTOR 0
#define LMOTOR 3

int main() 
{
	enable_servos();
	set_each_analog_state(1,0,0,0,0,0,0,0); // enable floating analog port for port 0
	
}
