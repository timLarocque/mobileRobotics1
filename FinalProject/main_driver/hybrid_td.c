#ifndef HYBRID_TD_H
#define HYBRID_TD_H

#include "driver.h"

#define LANCE_MIN 650
#define LANCE_RANGE 850

// call hybrid td normalize function
// use braitenberg to aim robot at shield
void attackShieldTD(Shield target) {
  
	NormalizedSpeed norm;
	norm = normalizeHybridTD(target);
	
	if(target.size >= 250) {
		if(target.xCentroid < 80) {
			mav(LMOTOR, norm.left);
			mav(RMOTOR, norm.right);
		} else {
			mav(LMOTOR, norm.right);
			mav(RMOTOR, norm.left);
		}
	} else {
		mav(LMOTOR, norm.left);
		mav(RMOTOR, norm.right);
	}
}

// initialize and return speed structure
// aims the robot towards the center of the opposing shield
NormalizedSpeed normalizeHybridTD(Shield target) {

  NormalizedSpeed speed;
  speed.left = (int)(((double)target.xCentroid / 160.0) * 500.0);
  speed.right = (int)(500 - (((double)target.xCentroid / 160.0) * 500.0));
  return speed;
										
}
 
void moveLanceHybridTD(Shield target) {
	int normalized = (int)(((double)target.xCentroid / 160.0) * LANCE_RANGE) + LANCE_MIN;
	if(normalized < LANCE_MIN) normalized = LANCE_MIN;
	else if(normalized > (LANCE_MIN + LANCE_RANGE)) normalized = LANCE_MIN + LANCE_RANGE;
	set_servo_position(LANCE, normalized);
}

// if you can't find the shield
// just keep moving forward
void locateShieldHybridTD() {		
	mav(RMOTOR, 200);
	mav(LMOTOR, 200);
}

#endif // for HYBRID_TD_H
