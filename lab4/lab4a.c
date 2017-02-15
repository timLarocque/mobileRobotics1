// Created on Mon Feb 13 2017 by Darin Beaudreau

#define LMOTOR 3
#define RMOTOR 0

#define SENSOR 0

// Enumerator to denote how far the robot is from the wall.
typedef enum distance { CLOSE, GOOD, FAR } distance;

void followWall();
distance range(int reading);

int main() {
	followWall();
	ao();
	
	printf("Program terminated...\n");
	
	return 0;
}

void followWall() {
	// Press the black button on the CBC to terminate the program.
	while(!black_button()) {
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
	if(reading >= 1000) return CLOSE; // May need to change this... max value is 1023, and if it gets that close, it will start to go down again because of that 4 inch buffer.
	else if(reading <= 600) return FAR; // Seems to work okay.
	else return GOOD;
}
