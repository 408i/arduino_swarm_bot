/*
  Wheel.h - Library for managing a bot's wheel and motor
  Created by Charles Hulcher, September 10, 2015.
*/
#ifndef Wheel_h
#define Wheel_h

#include "Arduino.h"

#define FORWARD           1
#define REVERSE           0

class Wheel
{
  public:
    Wheel(int pin, int aPin, int bPin);
    bool setSpeed(int speed);
    bool setDirection(int dir);
    void stop();
    int getSpeed();
  private:
    int _pin;
    int _a; // A pin for motor controller
    int _b; // B pin for motor controller
    int _speed;
};

#endif
