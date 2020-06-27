#include "system.h"
#include "carMotors.h"

int directionRight;
int directionLeft; // Directions // 1 Forward, 0 stop, -1 backward
int powerLeft;
int powerRight;

void setup() 
{                                                       //|   MOTOR A   ||   MOTOR B   |
	CMinit(13, 12, 6, 11, 10, 5); // Config your motors //|IN1, IN2, ENA||IN3, IN4, ENB|
}


void loop()
{
    CMsetSpeed(255,255); // Turn max speed on both motors
    delay(1000);
    CMforwardFor(1000);  // Set Forward for a definite time
    CMbackwardFor(1000); // Set Backward for a definite time
    delay(1000);

    CMsetSpeed(255,-255); // Turn different speed to motors.
    if(CMleftIsMoving()){ // If left motor is moving, do...
    	powerLeft = CMleftGet();
    	directionLeft = CMleftDirection();
    }

    if(CMrightIsMoving()){ // If right motor is moving, do...
    	powerRight = CMrightGet();
    	directionRight = CMrightDirection();
    }

}
