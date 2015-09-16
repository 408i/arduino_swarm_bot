/*
  Wheel.cpp - Library for managing a bot's wheel and motor
  Created by Charles Hulcher, September 10, 2015.
*/
#include "Arduino.h"
#include "Wheel.h"

Wheel::Wheel(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

bool Wheel::setSpeed(int speed)
{
	if( speed >= 0 || speed <= 255 ){
		analogWrite(_pin, speed);
		_speed = speed;
		return true;
	}
	return false;
}

void Wheel::stop()
{
	Wheel::setSpeed(0);
}

int Wheel::getSpeed()
{
	return _speed;
}