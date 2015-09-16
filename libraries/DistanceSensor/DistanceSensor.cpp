/*
  DistanceSensor.cpp - Library for managing bot's distance sensors
  Created by Charles Hulcher, September 12, 2015.
*/
#include "Arduino.h"
#include "DistanceSensor.h"

/**
* Constructor for distance sensor.
* @param {Int} pin - the pin to initialize sensor at
*/
DistanceSensor::DistanceSensor(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

/**
* Gets the current distance to sensor platform target and stores it
* in the distVals array, along with the angle to target.
* @param {Int} angle - the angle to read from 0-179.
*/
void DistanceSensor::readDistanceAtAngle(int angle) {
	// stores latest distance reading by angle read
	long reading = DistanceSensor::readPING();
	_distVals[angle] = reading;
}

/**
* Retrieve last read distance at an angle.
* @param {Int} angle - the angle to get from 0-179.
*/
long DistanceSensor::getDistanceAtAngle(int angle) {
	return _distVals[angle];
}

/**
* Gets the current distance to sensor platform target and stores it
* in the distVals array, along with the angle to target.
* @param {Int} numDistances - the number of distances to print (<= max index of distances [180])
*/
void DistanceSensor::printDistances(int numDistances) {
	int pos = 0;
	for(pos = 0; pos < numDistances; pos += 1){
		Serial.print( _distVals[pos] );
		Serial.print("cm, ");
	}
	Serial.println();
}

/**
* Reads from the PING))) ultrasonic sensor.
* Modified from Ping example.
* @returns {Long} distance to current target
*/
long DistanceSensor::readPING() {
	// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
	// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_pin, LOW);

	// The same pin is used to read the signal from the PING))): a HIGH
	// pulse whose duration is the time (in microseconds) from the sending
	// of the ping to the reception of its echo off of an object.
	pinMode(_pin, INPUT);
	long timing = pulseIn(_pin, HIGH);
	return microsecondsToCentimeters( timing );
}

/**
* Converts microsenconds to centimeters.
* @param {Long} microseconds - duration to convert
* @returns {Long} distance in centimeters
*/
long DistanceSensor::microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}