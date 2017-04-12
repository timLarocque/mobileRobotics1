// Created on Wed Apr 12 2017

#ifndef __OFFENSIVE_H__
#define __OFFENSIVE_H__

#include <stdio.h>
#include "offensiveStyle.c"

// defining all of the sensors
#define LMOTOR 3
#define RMOTOR 0
#define SHIELD 8
#define LANCE 1
#define LHAT 1
#define RHAT 0
#define GREEN 1

// Shield detection structure
typedef struct {
	int xCentroid;
	int yCentroid; 
	int size;
} Shield;

// function declarations
void approachShield();
void findShield();
void collisionDetection();
void moveLance();

#endif
