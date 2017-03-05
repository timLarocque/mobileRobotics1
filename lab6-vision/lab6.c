#include <stdio.h>

#define LMOTOR 3
#define RMOTOR 0

#define SERVO 0

#define SERVO_LEFT 800
#define SERVO_RIGHT 1900

void seekObject();
void followObject();
void kick();
void rotateLeft();

int main() {
	enable_servos();
	set_each_analog_state(1,0,0,0,0,0,0,0);
	set_servo_position(SERVO, SERVO_LEFT);
	msleep(500);
	
	seekObject();
	ao();
}

void seekObject() {
	// Continuously turn in a circle until it sees a ball.
	// Press the black button to terminate search.
	while(!black_button()) {
		track_update();
		if(track_size(0, 0) > (40 * 40)) {
			followObject();
		} else {
			rotateLeft();
		}
	}
}

void followObject() {
	while(1) {
		
	}
}

void kick() {
	set_servo_position(SERVO, SERVO_RIGHT);
	msleep(500);
	set_servo_position(SERVO, SERVO_LEFT);
	msleep(500);
}

void rotateLeft() {
	mav(LMOTOR, -300);
	mav(RMOTOR, 300);
}
