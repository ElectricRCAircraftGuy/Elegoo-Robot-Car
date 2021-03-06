//
// ---The following code is needed for the stepper motor---
//
#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  3     // IN1 on the ULN2003 driver 1
#define motorPin2  4     // IN2 on the ULN2003 driver 1
#define motorPin3  5     // IN3 on the ULN2003 driver 1
#define motorPin4  6     // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
//
// ---End of variables needed for Stepper Motor--- 
//

int timesToMove = 3;	// How many times to complete rotation sequence

void setup() {
	Serial.begin(115200); // This is for ease of debugging; starts the Serial Monitor (no effect on the functionality of your code; only helps you see what it's doing)

	// --- Initialization of Stepper Motor ---
	stepper1.setMaxSpeed(1000.0);
	stepper1.setAcceleration(100.0);
	stepper1.setSpeed(1000);
	// --- End of initialization of Stepper Motor
	
}//--(end setup )---

void loop() {
	
	while (timesToMove > 0){
		_moveStepperToPositionNow(stepper1, 4096);	
		delay(500);
		_moveStepperToPositionNow(stepper1, -2048);
		timesToMove = timesToMove - 1;
	}
}
