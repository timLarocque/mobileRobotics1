#include "defensiveStyle.h"

#ifndef DEFENSIVE_STYLE_C
#define DEFENSIVE_STYLE_C

#define LANCE_MIN 600
#define LANCE_RANGE 800

// Find Shield Function
// ARGUMENTS: none
//   RETURNS: shield structure
//   PURPOSE: return a struct containing updated position/size of shield
Shield findShield() {

	// update the image
	track_update();
	
	// make new shieled, update fields
	Shield target;
	target.xCentroid = track_x(RED, 0);
	target.yCentroid = track_y(RED, 0);
	target.size = track_size(RED, 0);

	// return updated shield
	return target;
	
}

void avoidShield() {

	// find the shield
	Shield target = findShield();
	
	// move lance
	moveLance(target);		
	
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
		mav(RMOTOR, norm.left);		// defense uses RMOTOR
		mav(LMOTOR, norm.right);	// defense uses LMOTOR
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

void moveLance(Shield shield) {
	int normalized = (int)(((double)shield.xCentroid / 160.0) * (LANCE_RANGE - shield.size)) + LANCE_MIN;
	if(normalized < LANCE_MIN) normalized = LANCE_MIN;
	else if(normalized > (LANCE_MIN + LANCE_RANGE)) normalized = LANCE_MIN + LANCE_RANGE;
	set_servo_position(LANCE, normalized);
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
