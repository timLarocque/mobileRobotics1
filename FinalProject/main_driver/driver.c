// Created on Wed Apr 12 2017

#include "driver.h"
#include "global_functions.c"
#include "offensive.c"
#include "defensive.c"
#include "hybrid_ve.c"
#include "hybrid_td.c"

int main() {
	
	// get ready
	int isJoustComplete = FALSE;
	int color = pickColor();
	int fightStyle = pickFightingStyle();

	// get set
	printf("Put me in the right corner of the arena, and press A to start.\n");
	while(!a_button()) {}
		
	// go
	while (!black_button() && !isJoustComplete) {	
		isJoustComplete = joust(color, fightStyle);
	}
	
	return 0;
	
}

int joust(int color, int fightStyle) {
		
	// variable declarations
	int isComplete = FALSE;		
	Shield target = findShield(color);
	
	// if the shield is offscreen, locate it
	if (target.size < 50) {	
		if (fightStyle == OFFENSIVE) locateShieldOffense();
		if (fightStyle == DEFENSIVE) locateShieldDefense();
		if (fightStyle == HYBRID_VE) locateShieldHybridVE();
		if (fightStyle == HYBRID_TD) locateShieldHybridTD();
	}
		
	// otherwise... 
	else {
		
		// move the lance appropriately
		if (fightStyle == OFFENSIVE) moveLanceOffense();
		if (fightStyle == DEFENSIVE) moveLanceDefense();
		if (fightStyle == HYBRID_VE) moveLanceHybridVE();
		if (fightStyle == HYBRID_TD) moveLanceHybridTD(target);

		// fight the other bot appropriately
		if (fightStyle == OFFENSIVE) approachShield(target);
		if (fightStyle == DEFENSIVE) avoidShield(target);
		if (fightStyle == HYBRID_VE) attackShieldVE(target);
		if (fightStyle == HYBRID_TD) attackShieldTD(target);

	}

	// keep robot within borders, check for defeat
	if (digital(SHIELD) == 1) isComplete = acceptDefeat();
	//if (analog10(LHAT) > 500) leftBorderControl();
	//if (analog10(RHAT) > 500) rightBorderControl();
				
	// return if the battle is complete
	return isComplete;

}
