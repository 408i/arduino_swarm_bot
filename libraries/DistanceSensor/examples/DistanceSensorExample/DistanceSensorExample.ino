/*
  DistanceSensorExample.ino - Example using the DistanceSensor library
  Created by Charles Hulcher, September 12, 2015.
*/
#include <DistanceSensor.h>

// give it the pin
DistanceSensor forwardUltrasonic(7);

void setup()
{
}

void loop()
{
	// read from the sensor
	// you can use any indices from 0 to 179 to store the values.
	forwardUltrasonic.readDistanceAtAngle(0);
	forwardUltrasonic.readDistanceAtAngle(1);
	forwardUltrasonic.readDistanceAtAngle(2);

	// get the value at position 0.
	forwardUltrasonic.getDistanceAtAngle(0);

	// print a bunch of readings.
	forwardUltrasonic.printDistances(3); // range of 0-2 is 3

}