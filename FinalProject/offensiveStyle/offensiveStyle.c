#include "offensiveStyle.h"

#ifndef OFFENSIVE_STYLE_C
#define OFFENSIVE_STYLE_C

// Find Shield Function
// ARGUMENTS: none
//   RETURNS: shield structure
//   PURPOSE: return a struct containing updated position/size of shield
Shield findShield() {

	// update the image
	track_update();
	
	// make new shieled, update fields
	Shield target;
	target.xCentroid = track_x(GREEN, 0);
	target.yCentroid = track_y(GREEN, 0);
	target.size = track_size(GREEN, 0);

	// return updated shield
	return target;

}

void approachShield() {
	/*
	while(!black_button()) {

		// find the shield
		Shield target = findShield();
						
		// if the centroid of the color blob 
		// is to the left of the center of the screen
		// turn right
		if (target.xCentroid < 75) {
			mav(RMOTOR, 200);
			mav(LMOTOR, -200);
		}
																											
		// if the centroid of the color blob
		// is to the right of the center of the screen
		// turn left
		else if (target.xCentroid > 85) {
			mrp(RMOTOR, -200);
			mrp(LMOTOR, 200);
		}
																																																	
		// otherwise, if the centroid of the color blob
		// is centered with respect to the screen
		// beep
		else {
			beep();
		}			

	}
	*/																																																																					
	return;

}

void collisionDetection() {
	
}

void moveLance() {
	
}

#endif
