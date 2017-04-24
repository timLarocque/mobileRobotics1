
#ifndef HYBRID_TD_H
#define HYBRID_TD_H

#include "driver.h"

// call hybrid td normalize function
// use braitenberg to aim robot at shield
void attackShieldTD(Shield target) {
  
	NormalizedSpeed norm;
	norm = normalize(target);
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
void moveLanceHybridTD() {
				
    set_servo_position(LANCE, 120);
		msleep(100);
		set_servo_position(LANCE, 80);
		msleep(100);

}

// if you can't find the shield
// just keep moving forward
void locateShieldHybridTD() {
				
  mav(RMOTOR, 100);
	mav(LMOTOR, 100);

}

#endif // for HYBRID_TD_H
