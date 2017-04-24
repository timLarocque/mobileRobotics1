
#ifndef DEFENSIVE_H
#ifndef DEFENSIVE_H

#include "driver.h"

// call the defensive normalize function
// use braitenberg to aim robot away from shield
void avoidShield(Shield target) {
				
  NormalizedSpeed norm;
	norm = normalize(target);
	mav(LMOTOR, norm.left);
	mav(RMOTOR, norm.right);
																																				
}

// initialize and return speed structure
// aims the robot away from the opposing shield
NormalizedSpeed normalizeDefense(Shield target) {

  NormalizedSpeed speed;
	speed.left = (int)(500 - (((double)target.xCentroid / 160.0) * 500.0));
	speed.right = (int)(((double)target.xCentroid / 160.0) * 500.0);
	return speed;				
				
}

// aim lance straight forward
// don't move it at all
void moveLanceDefense() {

    set_servo_position(LANCE, 1000);
				
}

// if you can't move the shield
// just keep moving forward
void locateShieldDefense() {

  mav(RMOTOR, 100);
  mav(LMOTOR, 100);				

}

#endif // for DEFENSIVE_H
