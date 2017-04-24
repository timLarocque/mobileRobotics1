// Robot Jousting!
// Team Razzle Frazzle Hybrid
// Created 04/24/2017

#include "hybridStyle.h"
#include "hybridStyle.c"

int main() {
	while(!black_button()) {
		Shield target = findShield();
		
		// If the shield is bumped, commit sudoku.
		/*if(digital(SHIELD)) {
			acceptDefeat();
			break;
		}*/
		
		// Determine behavior based on how close the shield is.
		if(target.size >= 300) {
			avoidShield(target);
		} else if(target.size >= 50) {
			approachShield(target);
		} else {
			moveForward();
		}
		
		moveLance(target);
	}
	
	return 0;
}
