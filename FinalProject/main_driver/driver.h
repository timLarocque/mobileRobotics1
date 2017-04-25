
#ifndef DRIVER_H
#define DRIVER_H

// include statements
#include <stdio.h>

// define all of the sensor/servo/motor ports
#define LMOTOR 3
#define RMOTOR 0
#define SHIELD 8
#define LANCE 1
#define LHAT 1
#define RHAT 0

// define globally useful variables
#define GREEN 1
#define RED 0
#define OFFENSIVE 0
#define DEFENSIVE 1
#define HYBRID_VE 2
#define HYBRID_TD 3
#define FALSE 0
#define TRUE 1

// shield detection structure
typedef struct {
	int xCentroid;
	int yCentroid; 
	int size;
} Shield;

// motor speed structure
typedef struct {
	int left;
	int right;
} NormalizedSpeed;

// global function declarations
int joust(int color, int fightStyle);
Shield findShield(int color);
int pickColor();
int pickFightingStyle();
int acceptDefeat();
void leftBorderControl();
void rightBorderControl();

// offense specific function declarations
void approachShield(Shield target);
NormalizedSpeed normalizeOffense(Shield target);
void moveLanceOffense();
void locateShieldOffense();

// defense specific function declarations
void avoidShield(Shield target);
NormalizedSpeed normalizeDefense(Shield target);
void moveLanceDefense();
void locateShieldDefense();

// hybrid_ve specific function declarations
void attackShieldVE(Shield target);
NormalizedSpeed normalizeHybridVE(Shield target);
void moveLanceHybridVE();
void locateShieldHybridVE();

// hybrid_td specific function declarations
void attackShieldTD(Shield target);
NormalizedSpeed normalizeHybridTD(Shield target);
void moveLanceHybridTD(Shield target);
void locateShieldHybridTD();

#endif
