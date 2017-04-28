#ifndef HYBRID_VE_H
#define HYBRID_VE_H

#include "driver.h"

// call hybrid ve normalize function
// use braitenberg to aim robot at shield
void attackShieldVE(Shield target) {

	NormalizedSpeed norm;
	norm = normalizeHybridVE(target);
	mav(LMOTOR, norm.left);
	mav(RMOTOR, norm.right);
												
}

// initialize and return speed structure
// aims the robot towards the left of the opposing shield
NormalizedSpeed normalizeHybridVE(Shield target) {
				
	NormalizedSpeed speed;
	speed.left = (int)(((double)target.xCentroid / 40.0) * 250.0);
	speed.right = (int)(500 - (((double)target.xCentroid / 40.0) * 250.0));
	return speed;
								
}

// aim the lance to the right
// don't move it at all
void moveLanceHybridVE() {

	set_servo_position(LANCE, 1250);
				
}

// if you can't find the shield
// just keep moving forward
void locateShieldHybridVE() {
  
	mav(RMOTOR, 100);
	mav(LMOTOR, 100);
									
}

#endif // for HYBRID_VE_H
