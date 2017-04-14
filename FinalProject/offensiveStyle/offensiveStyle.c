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
	NormalizedSpeed norm;
	
	// find the shield
	Shield target = findShield();
	do {
		target = findShield();
		mav(RMOTOR, 100);
		mav(LMOTOR, -100);
	} while (target.size < 50);
	
	norm = normalize(target);
	mav(LMOTOR, norm.left);
	mav(RMOTOR, norm.right);
	return;

}

NormalizedSpeed normalize(Shield target) {
	NormalizedSpeed temp;
	temp.left = (int)(target.xCentroid * 2.5);
	temp.right = (int)(400 - (target.xCentroid * 2.5));
}

void collisionDetection() {
	
}

void moveLance() {
	
}

#endif
