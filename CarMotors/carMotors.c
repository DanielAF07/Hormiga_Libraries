/*
 * Created By Daniel Anchondo on June 26, 2020.
 * CarMotors
 * Just an easy way to control your l298n and l293d.
 */

#include "system.h"
#include "carMotors.h"

#define adelante 1
#define atras -1
#define stop 0

#define false 0
#define true 1

typedef struct Motors{
	int pin1;
	int pin2;
	int pwm;
	int power;
    int direction;
    int isMoving;
} Motor;

    Motor left;
    Motor right;
    
void CMinit(unsigned int a1, unsigned int a2, unsigned int apwm, unsigned int b1, unsigned int b2, unsigned int bpwm){ //Init configuration to both motors.
    left.pin1 = a1;
    left.pin2 = a2;
    left.pwm = apwm;
	pinMode(left.pin1, OUTPUT);   // LEFT
	pinMode(left.pin2, OUTPUT);   // LEFT
	pinMode(left.pwm, OUTPUT);    // LEFT
    left.power = 0;
    left.direction = stop;
    left.isMoving = false;
    
    right.pin1 = b1;
    right.pin2 = b2;
    right.pwm = bpwm;
    pinMode(right.pin1, OUTPUT);   // RIGHT
	pinMode(right.pin2, OUTPUT);   // RIGHT
	pinMode(right.pwm, OUTPUT);    // RIGHT
    right.power = 0;
    right.direction = stop;
    right.isMoving = false;
}
    
void CMrightInit(unsigned int a1, unsigned int a2, unsigned int apwm){ // Init configuration to only right motor
    right.pin1 = a1;
    right.pin2 = a2;
    right.pwm = apwm;
    pinMode(right.pin1, OUTPUT);   // RIGHT
	pinMode(right.pin2, OUTPUT);   // RIGHT
	pinMode(right.pwm, OUTPUT);    // RIGHT
}

void CMleftInit(unsigned int b1, unsigned int b2, unsigned int bpwm){ // Init configuration to only left motor
    left.pin1 = b1;
    left.pin2 = b2;
    left.pwm = bpwm;
	pinMode(left.pin1, OUTPUT);   // LEFT
	pinMode(left.pin2, OUTPUT);   // LEFT
	pinMode(left.pwm, OUTPUT);    // LEFT  
}

void CMsetSpeed(int speedL, int speedR){ // Set speed on both motors.
	//LEFT
	if(speedL > 0){
		digitalWrite(left.pin1, HIGH);
		digitalWrite(left.pin2, LOW);
		analogWrite(left.pwm, speedL);
        left.direction = adelante;
        left.isMoving = true;
	} else if(speedL < 0){
		digitalWrite(left.pin1, LOW);
		digitalWrite(left.pin2, HIGH);
		analogWrite(left.pwm, speedL*-1);
        left.direction = atras;
        left.isMoving = true;
	} else if(speedL == 0){
		digitalWrite(left.pin1, LOW);
		digitalWrite(left.pin2, LOW);
		analogWrite(left.pwm, 0);
        left.direction = stop;
        left.isMoving = false;
	}

	//RIGHT
	if(speedR > 0){
		digitalWrite(right.pin1, HIGH);
		digitalWrite(right.pin2, LOW);
		analogWrite(right.pwm, speedR);
        right.direction = adelante;
        right.isMoving = true;
	} else if(speedR < 0){
		digitalWrite(right.pin1, LOW);
		digitalWrite(right.pin2, HIGH);
		analogWrite(right.pwm, speedR*-1);
        right.direction = atras;
        right.isMoving = true;
	} else if(speedR == 0){
		digitalWrite(right.pin1, LOW);
		digitalWrite(right.pin2, LOW);
		analogWrite(right.pwm, 0);
        right.direction = stop;
        right.isMoving = false;
	}
    left.power = speedL;
    right.power = speedR;
}

void CMstop(void){ // Stop motors 
	CMsetSpeed(0,0);
}

void CMforward(void){ // Go forward with max velocity.
    CMsetSpeed(255,255);
}

void CMforwardFor(unsigned int ms){ // Go forward only for a definite time
    CMsetSpeed(255,255);
    delay(ms);
    CMstop();
}

void CMbackward(void){ // Go backward in max velocity
    CMsetSpeed(-255,-255);
}

void CMbackwardFor(unsigned int ms){ // Go backward only for a definite time.
    CMsetSpeed(-255,-255);
    delay(ms);
    CMstop();
}

int CMleftGet(void){ // Return the speed of left Motor
    return left.power;
}

int CMrightGet(void){ // Return the speed of right motor
    return right.power;
}

int CMrightIsMoving(void){ // Return true if right motor is moving
    return right.isMoving;
}

int CMleftIsMoving(void){ // Return true if left motor is moving
    return left.isMoving;
}

int CMrightDirection(void){ // Return right motor direction  1 = Forward // 0 = stop // -1 = backward
    return right.direction;
}

int CMlefttDirection(void){ // Return left motor direction  1 = Forward // 0 = stop // -1 = backward
    return left.direction;
}

int CMdemo(void){ // A demo just for test your circuits.
    for(int i = 0; i < 3; i++){
        CMsetSpeed(255,255);
        delay(1000);
        CMsetSpeed(0,0);
        delay(250);
        CMsetSpeed(-255,-255);
        delay(1000);
        CMsetSpeed(0,0);
        delay(250);
        CMsetSpeed(-255,255);
        delay(1000);
        CMsetSpeed(0,0);
        delay(250);
        CMsetSpeed(255,-255);
        delay(1000);
        CMsetSpeed(0,0);
        delay(250);
    }
}
