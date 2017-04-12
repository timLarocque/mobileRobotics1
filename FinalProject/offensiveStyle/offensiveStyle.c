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
	
	// find the shield
	Shield target = findShield();
	do {
		target = findShield();
		mav(RMOTOR, 100);
		mav(LMOTOR, -100);
	} while (target.size < 200);
	
	//mav(LMOTOR, (target.xCentroid * 31));
	//mav(RMOTOR, (500 - (target.xCentroid * 31)));
		
	// if the centroid of the color blob 
	// is to the left of the center of the screen
	// turn right
	if (target.xCentroid < 75) {
		mav(RMOTOR, -200);
		mav(LMOTOR, 200);
		msleep(100);
	}
																										
	// if the centroid of the color blob
	// is to the right of the center of the screen
	// turn left
	else if (target.xCentroid > 85) {
		mav(RMOTOR, 200);
		mav(LMOTOR, -200);
		msleep(100);
	}
																																															
	// otherwise, if the centroid of the color blob
	// is centered with respect to the screen
	// beep
	else {
		mav(RMOTOR, 200);
		mav(LMOTOR, -200);
		msleep(100);
	}			
					
	return;

}

void collisionDetection() {
	
}

void moveLance() {
	
}

#endif
