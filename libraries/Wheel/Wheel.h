/*
  Wheel.h - Library for managing a bot's wheel and motor
  Created by Charles Hulcher, September 10, 2015.
*/
#ifndef Wheel_h
#define Wheel_h

#include "Arduino.h"

class Wheel
{
  public:
    Wheel(int pin);
    bool setSpeed(int speed);
    void stop();
    int getSpeed();
  private:
    int _pin;
    int _speed;
};

#endif
