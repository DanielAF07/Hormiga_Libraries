/*
 *HC SR04
 */
#include "system.h"
#include "HCSR04.h"


HCSR04 HCSR04init(int a, int b){
    HCSR04 new;
	T1CON  = 0x10;        // set Timer1 clock source to internal with 1:2 prescaler (Timer1 clock = 1MHz)
  	TMR1H  = TMR1L = 0;   // reset Timer1
    new.echoPin = a;
    new.triggerPin = b;
	pinMode(new.echoPin, INPUT);
    return new;
}

__bit wait_sensor(HCSR04 current)
{
  uint16_t i = 0;
  TMR1H  = TMR1L = 0;   // reset Timer1
  TMR1ON = 1;           // enable Timer1 module
  while(!digitalRead(current.echoPin) && (i < 1000))
    i = ( TMR1H << 8 ) | TMR1L;   // read Timer1 and store its value in i
 
  if(i >= 1000)
    return 0;
 
  else
    return 1;
}
 
__bit get_distance(uint16_t *ticks, HCSR04 current)
{
  *ticks = 0;
  TMR1H  = TMR1L = 0;     // reset Timer1
 
  while( digitalRead(current.echoPin) && (*ticks < 23200) )
    *ticks = ( TMR1H << 8 ) | TMR1L;    // read Timer1 value
 
  TMR1ON = 0;   // disable Timer1 module
 
  if (*ticks >= 23200)
    return 1;
 
  else
    return 0;
}

double getDistanceCM(HCSR04 sensor){
	// send 10us pulse to HC-SR04 Trigger pin
    digitalWrite(sensor.triggerPin, LOW);   // make sure trigger pin is low
    __delay_us(2);     // wait 2 us
    digitalWrite(sensor.triggerPin, HIGH);    // now generate the 10 us pulse
    __delay_us(10);    // wait 10 us
    digitalWrite(sensor.triggerPin, LOW); 
 
    // read pulse comes from HC-SR04 Echo pin
    if (wait_sensor(sensor))
    {    // if there is a response from the sensor
 
      uint16_t distance;
 
      if(get_distance(&distance, sensor))
      {       // if distance > 400 cm
        return 0;
      }
 
      else
      {
        distance = distance / 58;     // calculate the actual distance in cm
        return distance;
      }
 
    }
    __delay_ms(200);  // wait 200 ms
      // end if (wait_sensor())
}

double getDistanceInches(HCSR04 sensor){
    double distance = getDistanceCM(sensor);
    distance = distance/2.54;
    return distance;
}

double getDistanceFeets(HCSR04 sensor){
    double distance = getDistanceCM(sensor);
    distance = distance/30.48;
    return distance;
}

