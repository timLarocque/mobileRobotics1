#include "offensiveStyle.h"

void approachShield() {
	printf("Hello World");
}

Shield findShield() {

	track_update();
	
	Shield target;
	target.xCentroid = track_x(GREEN, 0);
	target.yCentroid = track_y(GREEN, 0);
	target.size = track_size(GREEN, 0);

	return target;

}

void collisionDetection() {
	
}

void moveLance() {
	
}
