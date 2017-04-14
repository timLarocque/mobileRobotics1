#define LMOTOR 3
#define RMOTOR 0

#define LANCE 1
#define SHIELD 8

#define LHAT 1
#define RHAT 0

#define RED 0
#define GREEN 1

/**
 * Distance milestones between camera and opponent shield.
 * 1200 -> bots are right up in each other's business
 * 900 -> bots are fairly close. Too close to start turning away. Attack!
 * 600 -> medium distance. Start turning away to defend!
 * 200 -> bot is pretty far away. Pursue it!
 **/

int main() {
	while(!black_button()) {
		track_update();
		int count = track_count(0);
		if(count > 0) {
			// Get the size of the blob and its position.
			int size = track_size(0, 0);
			int x = track_x(RED, 0);
			int y = track_y(RED, 0);
			// Normalize the x value to see how far across the screen it is.
			int normalized = (int)(((double)x / 160.0) * 1000);
			if(size >= 600) {
				// We're in defense range! Run away!
				printf("In defense range!\n");
				int left = 1000 - normalized;
				int right = normalized;
				mav(LMOTOR, left);
				mav(RMOTOR, right);
			} else if(size >= 50) {
				// Pursuit range! Get over here, you cheeky little c-
				printf("In pursuit range!\n");
				int left = normalized;
				int right = 1000 - normalized;
				mav(LMOTOR, left);
				mav(RMOTOR, right);
			}
		}
	}
}
