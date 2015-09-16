/*
  WheelExample.ino - Example using the Wheel library
  Created by Charles Hulcher, September 10, 2015.
*/
#include <Wheel.h>

// give it the pin
Wheel leftWheel(13);
Wheel rightWheel(12);

void setup()
{
}

void loop()
{
	// you can set the wheel speed 0-255
	bool success = leftWheel.setSpeed(100);
	// success == true

	success = rightWheel.setSpeed(500);
	// success == false

	// stop the wheel
	leftWheel.stop();

	// you can get the speed
	int speed = leftWheel.getSpeed();
}