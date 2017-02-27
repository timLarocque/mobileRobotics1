#define SERVO 1
#define SONAR 0

void getOut();

int main() {
	getOut();
}

void getOut() {
	int i;
	int servoPositions[] = {0, 475, 950, 1425, 1900};
	enable_servos();
	msleep(350);
	while(1) {
		for(i = 0; i <= 4; i++) {
			set_servo_position(SERVO, servoPositions[i]);
			msleep(1000);
		}
	}
}
