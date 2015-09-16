/**
  The Arduino control code for an ENEE408i wheeled robot.
  Charlie Hulcher, September 12, 2015
 */

#include <Wheel.h>
#include <DistanceSensor.h>
#include <XServo.h>

/**
* Globals init
*/
// Wheels
Wheel leftWheel(11);
Wheel rightWheel(10);

// Servos
int degreesOfRotation = 180;
XServo sensorPlatformServo(9, degreesOfRotation);

// Ultrasonic Sensors
DistanceSensor forwardUltrasonic(7);

/**
* Runs once at board boot
*/
void setup() {
	// Run a serial connection for debugging messages
	Serial.begin(9600);

	// startMoving();

	d("Setup complete.");
}

/**
* Runs continuously while board is powered
*/
void loop() {
	d("Sweeping sensor platform...");
	sensorPlatformServo.sweep(1, sweepStepper);
	forwardUltrasonic.printDistances(180);
}

/**
* Gets called by the servo at every step. Calls the sensors to read.
* @param {Int} pos - the position of the servo
*/
void sweepStepper(int pos) {
	forwardUltrasonic.readDistanceAtAngle(pos);
}

/**
* Sets the bot's wheel speed
*/
void startMoving() {
	int speedValue = 125; // 0-255
	leftWheel.setSpeed(speedValue);
	rightWheel.setSpeed(speedValue);
	Serial.print(speedValue);
	d("/255 Speed set.");
}

/**
* Sweeps the sensor platform and calls for sensor reads
* at each position.
* Modified from Sweep example.
*/
void sweepSensorPlatform() {
	int pos = 0;
	for(pos = 0; pos < degreesOfRotation; pos += 1){
		sensorPlatformServo.write(pos);
		delay(15);
		forwardUltrasonic.readDistanceAtAngle(pos);
	}
}

/**
* Shorthand for calling serial port to write a debug message
* @param {String} message - the string message to print
*/
void d(char message[]) {
	Serial.print(message);
	Serial.println();
}

