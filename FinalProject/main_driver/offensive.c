
#ifndef OFFENSIVE_H
#define OFFENSIVE_H

#include "driver.h"

// call offensive normalize function
// use braitenberg to aim robot at shield
void approachShield(Shield target) {
  
	NormalizedSpeed norm;
	norm = normalizeOffense(target);
	mav(LMOTOR, norm.left);
	mav(RMOTOR, norm.right);
								
}

// initialize and return speed structure
// aims the robot towards the center of the opposing shield
NormalizedSpeed normalizeOffense(Shield target) {

  NormalizedSpeed speed;
  speed.left = (int)(((double)target.xCentroid / 160.0) * 500.0);
  speed.right = (int)(500 - (((double)target.xCentroid / 160.0) * 500.0));
  return speed;
										
}

// aim lance straight forward
// shake it back and forth a bit 
void moveLanceOffense() {
				
    set_servo_position(LANCE, 1020);
	msleep(100);
	set_servo_position(LANCE, 980);
	msleep(100);

}

// if you can't find the shield
// just keep moving forward
void locateShieldOffense() {
				
  mav(RMOTOR, 100);
	mav(LMOTOR, 100);

}

#endif // for OFFENSIVE_H
