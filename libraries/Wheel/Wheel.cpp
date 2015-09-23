/*
  Wheel.cpp - Library for managing a bot's wheel and motor
  Created by Charles Hulcher, September 10, 2015.
*/
#include "Arduino.h"
#include "Wheel.h"

Wheel::Wheel(int pin, int aPin, int bPin)
{
  _pin = pin;
  _a = aPin;
  _b = bPin;

  pinMode(_pin, OUTPUT);
  pinMode(_a, OUTPUT);
  pinMode(_b, OUTPUT);
  this->setDirection(FORWARD);
}

/**
* Sets speed and direction of spin.
* @param {Int} speed - -255:255 valued speed. Negative for reverse.
*/
bool Wheel::setSpeed(int speed)
{
	if( speed >= -255 || speed <= 255 ){
		if( speed >= 0 ){
			this->setDirection(FORWARD);
		}
		else{
			this->setDirection(REVERSE);
		}
		analogWrite(_pin, abs(speed));
		_speed = speed;
		return true;
	}
	return false;
}

/**
* Sets direction of wheel spin.
* @param {Enum} dir - 0 for backwards and 1 for forwards
*/
bool Wheel::setDirection(int dir){
	if( dir == FORWARD || dir == REVERSE ){
		if( dir == REVERSE ){
			digitalWrite(_a, LOW);
			digitalWrite(_b, HIGH);
		}
		else{
			digitalWrite(_a, HIGH);
			digitalWrite(_b, LOW);
		}
	}
	return false;
}

void Wheel::stop()
{
	this->setSpeed(0);
}

int Wheel::getSpeed()
{
	return _speed;
}