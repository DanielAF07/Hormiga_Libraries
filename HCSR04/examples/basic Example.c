#include "system.h"
#include "HCSR04.h"

HCSR04 sensor;

void setup(){
	sensor1 = HCSR04init(11,10);
    pinMode(13, OUTPUT);
}

void loop(){
    int distance = getDistanceCM(sensor1);
    if(distance < 10){ // Si la distancia es menor a 10 cm
        digitalWrite(13, HIGH);
    }
}