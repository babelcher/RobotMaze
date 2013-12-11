#include <msp430g2553.h>
#include "RobotMotionLibrary/robot_motion.h"
#include "RobotSensors/robot_sensors.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	InitializeADC10();
	InitPinsOut();
	InitTimer();

	while (1) {

		if (LeftSensorReading() < 0x250) {
			moveLeftForward25Percent();
			moveRightForward();

		} else {
			stopRight();
			moveLeftForward();
		}
	}
	return 0;
}

#