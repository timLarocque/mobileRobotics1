#include <stdio.h>

#define LMOTOR 3
#define RMOTOR 0

void followObject();

int main() {
	followObject();
	ao();
}

void followObject() {
	int leftValue, rightValue, numberOfBlobs;
	while(!black_button()) {
		track_update();
		track_count(3);
	}
}
