#define LMOTOR 3
#define RMOTOR 0

#define LANCE 1
#define SHIELD 8

#define LHAT 1
#define RHAT 0

#define RED 0
#define GREEN 1

#define LANCE_MIN 400
#define LANCE_RANGE 1000

/**
 * Distance milestones between camera and opponent shield.
 * 1200 -> bots are right up in each other's business
 * 900 -> bots are fairly close. Too close to start turning away. Attack!
 * 600 -> medium distance. Start turning away to defend!
 * 200 -> bot is pretty far away. Pursue it!
 **/
 
 typedef struct {
	int x, y, size; 
 } Shield;
 
 void aimLance(Shield shield);

int main() {
	enable_servos();
	set_servo_position(LANCE, (LANCE_MIN + 300));
	
	while(!black_button()) {
		if(digital(SHIELD)) {
			beep();
			printf("Blargh, I'm dead!\n");
			break;
		}
		
		track_update();
		int count = track_count(0);
		if(count > 0) {
			// Get the size of the blob and its position.
			Shield shield;
			shield.size = track_size(0, 0);
			shield.x = track_x(RED, 0);
			shield.y = track_y(RED, 0);
			
			aimLance(shield);
			
			// Normalize the x value to see how far across the screen it is.
			int normalized = (int)(((double)shield.x / 160.0) * 500);
				
			if(shield.size >= 300) {
				// We're in defense range! Run away!
				printf("In defense range!\n");
				int left = 500 - normalized;
				int right = normalized;
				mav(LMOTOR, left);
				mav(RMOTOR, right);
			} else if(shield.size >= 50) {
				// Pursuit range! Get over here, you cheeky little sh-
				printf("In pursuit range!\n");
				int left = normalized;
				int right = 500 - normalized;
				mav(LMOTOR, left);
				mav(RMOTOR, right);
			}
		} else {
			// Turn right until we find it again?
			mav(LMOTOR, 200);
			mav(RMOTOR, -200);
		}
	}
	
	disable_servos();
}

void aimLance(Shield shield) {
	int normalized = (int)(((double)shield.x / 160.0) * (LANCE_RANGE - shield.size)) + LANCE_MIN;
	set_servo_position(LANCE, normalized);
}
