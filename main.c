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

		if (LeftSensorReading() > 0x250) {
			moveRightForward25Percent();
			moveLeftForward();
			__delay_cycles(2000);

		} else if(LeftSensorReading() < 0x2A0){
			moveLeftForward25Percent();
			moveRightForward();
			__delay_cycles(2000);
		}
		else{
			moveForward();
			__delay_cycles(1000);
		}

		if (CenterSensorReading() > 0x250) {
			moveLeftForward();
			moveRightBackward();
			__delay_cycles(10000);
		}

	}
	return 0;
}

#
