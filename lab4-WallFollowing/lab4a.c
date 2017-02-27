// Created on Mon Feb 13 2017 by Darin Beaudreau

#define LMOTOR 3
#define RMOTOR 0

#define LBUMP 10
#define RBUMP 8

#define SENSOR 0

// Enumerator to denote how far the robot is from the wall.
typedef enum distance { CLOSE, GOOD, FAR } distance;

void followWall();
distance range(int reading);
void collisionDetection();

int main() {
	followWall();
	ao();

	printf("Program terminated...\n");

	return 0;
}

void followWall() {
	// Press the black button on the CBC to terminate the program.
	while(!black_button()) {
		// If we've collided with something, turn 90 degrees to the left.
		collisionDetection();

		// Get the distance reading from the sensor.
		int reading = analog10(SENSOR);

		// Use the enumerator to determine if this range is too close, too far, or just right.
		distance d = range(reading);

		if(d == CLOSE) {
			// If we're too close, turn to the right.
			mav(LMOTOR, -200);
			mav(RMOTOR, 300);
		} else if(d == FAR) {
			// If we're too far, turn to the left.
			mav(LMOTOR, 300);
			mav(RMOTOR, -200);
		} else {
			// If we're juuuuuuuuuuuuust right, drive straight.
			mav(LMOTOR, 400);
			mav(RMOTOR, 400);
		}
	}
}

distance range(int reading) {
	// A high value indicates a closer object and a low value indicates a far object.
	if(reading >= 700) return CLOSE; // May need to change this... max value is 1023, and if it gets that close, it will start to go down again because of that 4 inch buffer.
	else if(reading <= 400) return FAR; // Seems to work okay.
	else return GOOD;
}

void collisionDetection() {
	// If either bump sensor is triggered, turn 90 degrees left.
	if(digital(LBUMP) || digital(RBUMP)) {
		ao();
		msleep(50);

		// Back up a bit.
		mav(LMOTOR, -300);
		mav(RMOTOR, -300);
		msleep(100);
		ao();

		// Turn 90 degrees left.
		mav(LMOTOR, -500);
		mav(RMOTOR, 500);
		msleep(1250);
		ao();
	}
}
