// Created on Wed Apr 12 2017

#include "offensiveStyle_.h"
#include "offensiveStyle_.c"

int main() {
	
	// initialize shield position
	Shield target = findShield();
		
	// unless you hit the black button...
	while (!black_button()) {	
		
		// approach the shield
		approachShield();	
		
		// if the shield is tagged
		if (digital(SHIELD) == 1) {
			acceptDefeat();
		}
		/*
		// if black is detected on left side, veer right
		if (analog10(LHAT) > 500) { 
			avoid_border_left();
		} 
		
		// if black is detected on right side, veer left
		if (analog10(RHAT) > 500) { 
			avoid_border_right();
		}*/
		
	}
	
	return 0;
	
}
