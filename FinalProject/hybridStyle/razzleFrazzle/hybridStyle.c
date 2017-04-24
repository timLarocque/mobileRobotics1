// Find Shield Function
// ARGUMENTS: none
//   RETURNS: shield structure
//   PURPOSE: return a struct containing updated position/size of shield
Shield findShield() {
	// update the image
	track_update();

	// make new shield, update fields
	Shield target;
	target.x = track_x(GREEN, 0);
	target.y = track_y(GREEN, 0);
	target.size = track_size(GREEN, 0);

	// return updated shield
	return target;
}

// Approach Shield Function
// ARGUMENTS: none
//   RETURNS: none
//   PURPOSE: Follows the enemy shield as to hunt and poke the shield
void approachShield(Shield target) {
	// move lance
	moveLance();

	// if the sheild is offscreen, go forward
	if (target.size < 50) {
		target = findShield();
		mav(RMOTOR, 100);
		mav(LMOTOR, 100);
	}

	// otherwise, approach the shield
	else {
		NormalizedSpeed norm;
		norm = normalize(target);
		mav(LMOTOR, norm.left);
		mav(RMOTOR, norm.right);
	}
}

void hybridFight(Shield target) {
  NormalizedSpeed norm = normalize(target);
  if (target.size < 50) {
    mav(RMOTOR, 100);
    mav(LMOTOR, 100);
  } else if (target.size >= 50){
    mav(RMOTOR, norm.right);
    mav(LMOTOR, norm.left);
  } else {
    mav(LMOTOR, norm.right);
    mav(RMOTOR, norm.left);
    moveLance(target);
  }
}

// Normalizing Speed Function
// ARGUMENTS: Shield structure
//   RETURNS: A Normalized Speed Structure
//   PURPOSE: Takes a Shield structure and allows for Braitenberg style speed
NormalizedSpeed normalize(Shield target) {
	NormalizedSpeed temp;
	temp.left = (int)(((double)target.x / 160.0) * 500.0);
	temp.right = (int)(500 - (((double)target.x / 160.0) * 500.0));

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
}

void avoid_border_left() {
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);

	bmd(LMOTOR);
	bmd(RMOTOR);

	mrp(LMOTOR, 500, 400);
	bmd(LMOTOR);
}

void avoid_border_right() {
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);

	bmd(LMOTOR);
	bmd(RMOTOR);

	mrp(RMOTOR, 500, 400);
	bmd(RMOTOR);
}
