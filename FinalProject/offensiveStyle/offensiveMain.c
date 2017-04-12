// Created on Wed Apr 12 2017

#include "offensiveStyle.h"
#include "offensiveStyle.c"

int main() {

	Shield target = findShield();
	printf(" X Centroid : %d", target.xCentroid);
	printf(" Y Centroid : %d", target.yCentroid);
	printf("Shield Size : %d", target.size);

	return 0;
	
}
