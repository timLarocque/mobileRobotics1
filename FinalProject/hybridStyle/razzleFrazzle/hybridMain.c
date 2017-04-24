// Robot Jousting!
// Team Razzle Frazzle Hybrid

#include "hybridStyle.h"
#include "hybridStyle.c"

int main() {
	while(!black_button()) {
		track_update();
		
		Shield target = findShield();
		//target.xCentroid = track_x(RED, 0);
		//target.yCentroid = track_y(RED, 0);
		//target.size = track_size(RED, 0);
	}
	
	return 0;
}
