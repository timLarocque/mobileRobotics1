// Created on Wed Feb 22 2017 by Darin Beaudreau

#define SERVO 0
#define LMOTOR 3
#define RMOTOR 0
#define SENSOR 0

#define DEGREE 500

int positions[] = { 700, 1000, 1300, 1600, 1900 }; // Use these five positions to take readings.

int sensorToDistance(int value);
void turnTowards(int value);

int main() {
	int i;
	
	enable_servos();
	set_each_analog_state(1,0,0,0,0,0,0,0); // Enable floating analog port for port 0.
	set_servo_position(SERVO, positions[2]); // Set the starting position to be centered.
	
	// Press the black button to terminate the program early.
	while(!black_button()) {
		// Record the five values from the five positions.
		int max = 0;
		int maxPos = -1;
		for(i = 0; i < 5; i++) {
			set_servo_position(SERVO, positions[i]);
			
			msleep(250); // Wait for the signal to return.
			int value = analog10(SENSOR);
			printf("Reading %d : %d\n", i, value);
			if(value > max) {
				max = value; // We only care about the max value.
				maxPos = i; // Make sure we know which way to turn.
			}
		}
		turnTowards(maxPos);
		set_servo_position(SERVO, positions[2]);
		mav(LMOTOR, 500);
		mav(RMOTOR, 500);
		msleep(2048 - max);
		ao();
	}
	
	disable_servos();
	
	return 0;
}

// Convert the sensor value to inches.
int sensorToDistance(int value) {
	double percentage = ((double)value) / 1024.0;
	return (int)(percentage * 248) + 6;
}

// Orient the robot towards the direction with the largest reading from the sensor.
void turnTowards(int value) {
	if(value == -1) {
		// Shouldn't happen, but if so, just break out.
		printf("ERROR: Can't turn towards -1!\n");
		return;
	}
	
	int orient = value - 2; // Where is this value in relation to the center orientation?
	int delay = ((orient < 0)?-orient:orient) * DEGREE;
	
	mav(LMOTOR, ((orient < 0)?-500:500));
	mav(RMOTOR, ((orient < 0)?500:-500));
	msleep(delay);
	ao();
}
