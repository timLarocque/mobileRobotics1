// Created on Wed Apr 12 2017

#include "offensiveStyle.h"
#include "offensiveStyle.c"

int main() {
	while(!black_button()) {
		Shield target = findShield();
		printf(" X Centroid : %d\n", target.xCentroid);
		printf(" Y Centroid : %d\n", target.yCentroid);
		printf("Shield Size : %d\n\n", target.size);
		approachShield();	
	}
	
	return 0;
	
}
