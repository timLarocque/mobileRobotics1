// Created on Wed Apr 26 2017

#include <stdio.h>
#include "driver.h"

int main() 
{
	while(!black_button()) {
		if(digital(SHIELD)) {
			beep();
			beep();
			beep();
			beep();
		}
	}
}
