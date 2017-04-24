// Created on Wed Apr 12 2017

#include "pureStyle.h"

int pickColor() {

	int color = -1;

	printf("\nWhat color shield am I fighting?\n");
	printf("\tA: red\n");
	printf("\tB: green\n");
	printf("\n");

	while (color == -1) {
		if (a_button()) color = RED;
		if (b_button()) color = GREEN;
	}

	return color;

}

int pickFightingStyle() {

	int fighting_style = -1;

	printf("\nWhat fighting style should I use?\n");
	printf("\tUp: offensive\n");
	printf("\tDown: defensive\n");
	printf("\tLeft: hybrid ve\n");
	printf("\tRight: hybrid td\n");
	printf("\n");

	while (fighting_style = -1) {
		if (up_button())    fight_style = OFFENSIVE;				
		if (down_button())  fight_style = DEFENSIVE;				
		if (left_button())  fight_style = HYBRID_VE;				
		if (right_button()) fight_style = HYBRID_TD;				
	}

	return fighting_style;

}


Shield findShield(int color) {

	// update the image
	track_update();
	
	// make new shieled, update fields
	Shield target;
	target.xCentroid = track_x(color, 0);
	target.yCentroid = track_y(color, 0);
	target.size = track_size(color, 0);

	// return updated shield
	return target;
	
}

void leftBorderControl() {
	
	// move backwards a bit
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);
	bmd(LMOTOR);
	bmd(RMOTOR);

	// move right a bit
	mrp(LMOTOR, 500, 400); 
	bmd(LMOTOR);
	
}

void rightBorderControl() {
	
	// move backwards a bit
	mrp(RMOTOR, 500, -500);
	mrp(LMOTOR, 500, -500);
	bmd(LMOTOR);
	bmd(RMOTOR);
			
	// move left a bit
	mrp(RMOTOR, 500, 400); 
	bmd(RMOTOR);
	
}

int acceptDefeat() {
	
	// beep a few times in pain
	beep();
	beep();
	beep();
	
	// move backwards
	mrp(RMOTOR, 1000, -800);
	mrp(LMOTOR, 1000, -800);
	bmd(RMOTOR);
	bmd(LMOTOR);
	
	// turn left a lot to face away from opponent
	mrp(RMOTOR, 1000, 800);
	mrp(LMOTOR, 1000, -800);
	bmd(RMOTOR);
	bmd(LMOTOR);

	return 0;
	
}

