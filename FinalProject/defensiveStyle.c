#define LMOTOR 3
#define RMOTOR 0

#define LANCE 1
#define SHIELD 8

#define LHAT 1
#define RHAT 0

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
			int size = track_size(0, 0);
			if(size >= 1200) {
				// too close!
			} else if(size >= 900) {
				// attack!
			} else if(size >= 600) {
				// defend! run away!
			} else if(size >= 200) {
				// pursue!
			} else {
				// idk, my bff jill?
			}
		}
	}
}
