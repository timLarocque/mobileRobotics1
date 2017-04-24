#include "hybridStyle.h"

#ifndef HYBRID_STYLE_C
#define HYBRID_STYLE_C

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
	
	// move lance
	moveLance();		
	
	// if the shield is offscreen, go forward
	if (target.size < 50) {	
		target = findShield();
		mav(RMOTOR, 100);
		mav(LMOTOR, 100);
	}
	
	// otherwise, approach the shield
	else {
		NormalizedSpeed norm;
		norm = normalize(target);
		mav(LMOTOR, norm.left);		// offense uses LMOTOR
		mav(RMOTOR, norm.right);	// offense uses RMOTOR
	}
		
}

NormalizedSpeed normalize(Shield target) {
	
	NormalizedSpeed temp;
	temp.left = (int)(((double)target.xCentroid / 160.0) * 1000.0);
	temp.right = (int)(1000 - (((double)target.xCentroid / 160.0) * 1000.0));
		
	return temp;

}

void acceptDefeat() {
	
	// beep a few times in pain
	beep();
	beep();
	beep();
	
	// curve left/backwards
	mrp(RMOTOR, 1000, -800);
	mrp(LMOTOR, 1000, -800);
	bmd(RMOTOR);
	bmd(LMOTOR);
	
	// turn left a lot to face away from opponent
	mrp(RMOTOR, 1000, 800);
	mrp(LMOTOR, 1000, -800);
	bmd(RMOTOR);
	bmd(LMOTOR);

	while(!black_button()) {
			ao();
	}
	
}

void moveLance() {
			
	set_servo_position(LANCE, 1020);
	msleep(100);
	set_servo_position(LANCE, 1080);
	msleep(100);
	
}

void avoid_border_left() {
	
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);

	bmd(LMOTOR);
	bmd(RMOTOR);

	mrp(LMOTOR, 500, 400); 
	bmd(LMOTOR);
	
	return;
	
}

void avoid_border_right() {
	
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);

	bmd(LMOTOR);
	bmd(RMOTOR);
			
	mrp(RMOTOR, 500, 400); 
	bmd(RMOTOR);
	
	return;
	
}

#endif
