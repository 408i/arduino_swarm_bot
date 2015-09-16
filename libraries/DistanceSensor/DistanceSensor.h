/*
  DistanceSensor.h - Library for managing distance sensors
  Created by Charles Hulcher, September 12, 2015.
*/
#ifndef DistanceSensor_h
#define DistanceSensor_h

#include "Arduino.h"

class DistanceSensor
{
	public:
        DistanceSensor(int pin);
        void readDistanceAtAngle(int angle);
        long getDistanceAtAngle(int angle);
        void printDistances(int numDistances);
	private:
        long readPING();
        long microsecondsToCentimeters(long microseconds);
        long _distVals[180];
        int _pin;
};

#endif
