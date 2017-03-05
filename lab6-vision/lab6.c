#include <stdio.h>

#define LMOTOR 3
#define RMOTOR 0

#define SERVO 0

#define SERVO_LEFT 800
#define SERVO_RIGHT 1900

typedef enum direction { LEFT, RIGHT } direction;

direction turnDir;

void seekObject();
void followObject();
void kick();
void rotate(direction dir);

int main() {
	// Reset our "kick" servo.
	enable_servos();
	set_each_analog_state(1,0,0,0,0,0,0,0);
	set_servo_position(SERVO, SERVO_LEFT);
	msleep(500);
	
	// The starting turn direction can be either left or right.
	// This is just so it turns in some direction when the ball is initially not found.
	turnDir = LEFT;
	
	// Start looking for the ball.
	seekObject();
	ao();
}

void seekObject() {
	// Turn continuously in the last known direction the ball was moving until we see it.
	while(!black_button()) {
		track_update();
		// Look for a blob on channel 0 (our pre-defined red channel) big enough to be the ball.
		if(track_size(0, 0) > (40 * 40)) {
			// There is a blob on screen big enough to be our ball. Follow it.
			followObject();
		} else {
			// We can't see anything. Continue seeking...
			rotate(turnDir);
		}
	}
}

void followObject() {
	track_update();
	
	// Normalize the X value of the blob to be a value between 1-1000.
	int nx = (int)(((double)track_x(0, 0) / 160.0) * 1000.0);
		
	// If the blob is more towards the left, turn left when the ball goes off-screen.
	if(nx < 500) turnDir = LEFT;
	// However, if it's more towards the right, turn right when it's off-screen.
	else turnDir = RIGHT;
	
	// Use the normalized X value as a parameter to the motors for a Braitenberg approach.
	mav(LMOTOR, nx);
	mav(RMOTOR, (1000 - nx));
	
	// Is the blob close to the robot?
	if(track_y(0, 0) > 80) {
		// If so, kick it away!
		kick();
	}
	
}

void kick() {
	// Move the servo back and forth to "kick" whatever is in front of the bot.
	set_servo_position(SERVO, SERVO_RIGHT);
	msleep(500);
	set_servo_position(SERVO, SERVO_LEFT);
	msleep(500);
}

void rotate(direction dir) {
	mav(LMOTOR, ((dir == LEFT)?-300:300));
	mav(RMOTOR, ((dir == LEFT)?300:-300));
}
