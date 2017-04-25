
#ifndef HYBRID_TD_H
#define HYBRID_TD_H

#include "driver.h"

#define LANCE_MIN 600
#define LANCE_RANGE 800

// call hybrid td normalize function
// use braitenberg to aim robot at shield
void attackShieldTD(Shield target) {
  
	NormalizedSpeed norm;
	norm = normalizeHybridTD(target);
	mav(LMOTOR, norm.left);
	mav(RMOTOR, norm.right);
								
}

// initialize and return speed structure
// aims the robot towards the center of the opposing shield
NormalizedSpeed normalizeHybridTD(Shield target) {

  NormalizedSpeed speed;
  speed.left = (int)(((double)target.xCentroid / 160.0) * 500.0);
  speed.right = (int)(500 - (((double)target.xCentroid / 160.0) * 500.0));
  return speed;
										
}

// aim lance straight forward
// shake it back and forth a bit 
void moveLanceHybridTD(Shield target) {
	int normalized = (int)(((double)target.xCentroid / 160.0) * (LANCE_RANGE - target.size)) + LANCE_MIN;
	if(normalized < LANCE_MIN) normalized = LANCE_MIN;
	else if(normalized > (LANCE_MIN + LANCE_RANGE)) normalized = LANCE_MIN + LANCE_RANGE;
	set_servo_position(LANCE, normalized);

}

// if you can't find the shield
// just keep moving forward
void locateShieldHybridTD() {
				
  mav(RMOTOR, 100);
	mav(LMOTOR, 100);

}

#endif // for HYBRID_TD_H
