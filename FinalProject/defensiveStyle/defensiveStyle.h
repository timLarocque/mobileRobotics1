// Created on Wed Apr 12 2017

#ifndef DEFENSIVE_STYLE_H
#define DEFENSIVE_STYLE_H

// include statements
#include <stdio.h>

// defining all of the sensors
#define LMOTOR 3
#define RMOTOR 0
#define SHIELD 8
#define LANCE 1
#define LHAT 1
#define RHAT 0
#define RED 0

// Shield detection structure
typedef struct {
	int xCentroid;
	int yCentroid; 
	int size;
} Shield;

typedef struct {
	int left;
	int right;
} NormalizedSpeed;

// function declarations
Shield findShield();
void avoidShield();
void acceptDefeat();
void moveLance(Shield shield);
NormalizedSpeed normalize(Shield target);
void avoid_border_left();
void avoid_border_right();


#endif
