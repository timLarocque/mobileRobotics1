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
	
	while (!black_button()) {
		
		// find the shield
		Shield target = findShield();
		
		// if the sheild is offscreen, turn right
		if (target.size < 50) {	
			target = findShield();
			mav(RMOTOR, 100);
			mav(LMOTOR, -100);
		}
		
		// otherwise, approach the shield
		else {
			NormalizedSpeed norm;
			norm = normalize(target);
			mav(LMOTOR, norm.left);
			mav(RMOTOR, norm.right);
			printf("xlocation : %d\n", target.xCentroid);
			printf("left motor: %d\n", norm.left);
			printf("left motor: %d\n", norm.right);
		}
		
	}

}

NormalizedSpeed normalize(Shield target) {
	
	NormalizedSpeed temp;
	temp.left = (int)(((double)target.xCentroid / 160.0) * 1000.0);
	temp.right = (int)(1000 - (((double)target.xCentroid / 160.0) * 1000.0));
		
	return temp;

}

void collisionDetection() {
	
}

void moveLance() {
	
}

#endif
