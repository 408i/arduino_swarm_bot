/**
  The Arduino control code for an ENEE408i wheeled robot.
  Charlie Hulcher, September 12, 2015
 */

#include <Wheel.h>
#include <DistanceSensor.h>
// #include <XServo.h>
#include <Servo.h>

/**
* Globals init
*/
// Wheels
int leftA = 3;
int leftB = 2;
int rightA = 13;
int rightB = 12;
Wheel leftWheel(11, leftA, leftB);
Wheel rightWheel(10, rightA, rightB);

// some important comment

// Servos
int degreesOfRotation = 180;
// XServo sensorPlatformServo(9, degreesOfRotation);
Servo sensorPlatformServo;

// Ultrasonic Sensors
DistanceSensor forwardUltrasonic(7);

/**
* Runs once at board boot
*/
void setup() {
	// Run a serial connection for debugging messages
	sensorPlatformServo.attach(9);

	Serial.begin(9600);

	startMoving();

	d("Setup complete.");
}

/**
* Runs continuously while board is powered
*/
void loop() {
	d("Sweeping sensor platform...");
	// sensorPlatformServo.sweep(1, sweepStepper);
	sweep();
	forwardUltrasonic.printDistances(180);
}

/**
* Gets called by the servo at every step. Calls the sensors to read.
* @param {Int} pos - the position of the servo
*/
void sweepStepper(int pos) {
	forwardUltrasonic.readDistanceAtAngle(pos);
}

void sweep(){
  int start = 37;
  int ends = 127;
	int pos = 0;
	for(pos = start; pos <= ends; pos += 2) // goes from 0 degrees to 180 degrees 
	{                                  // in steps of 1 degree 
		sensorPlatformServo.write(pos);              // tell servo to go to position in variable 'pos' 
		 //delay(15-7);                       // waits 15ms for the servo to reach the position 
		 sweepStepper(pos);
	}
 /*
	for(pos = ends; pos>=start; pos-=1)     // goes from 180 degrees to 0 degrees 
	{                                
		sensorPlatformServo.write(pos);              // tell servo to go to position in variable 'pos' 
		 //delay(15-7);                       // waits 15ms for the servo to reach the position 
		 sweepStepper(pos);
	}
 */
}

/**
* Sets the bot's wheel speed
*/
void startMoving() {
	int speedValue = 255; // 0-255
	leftWheel.setSpeed(speedValue);
	rightWheel.setSpeed(speedValue);
	Serial.print(speedValue);
	d("/255 Speed set.");
}

/**
* Shorthand for calling serial port to write a debug message
* @param {String} message - the string message to print
*/
void d(char message[]) {
	Serial.print(message);
	Serial.println();
}

