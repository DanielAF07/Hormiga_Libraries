/*
 *HC SR04
 */
#include "system.h"
#include "HCSR04.h"
//#define ECHO_PIN      RB0
//#define TRIGGER_PIN   RB1

int ECHO_PIN;
int TRIGGER_PIN;

void HCSR04init(int a, int b){
	T1CON  = 0x10;        // set Timer1 clock source to internal with 1:2 prescaler (Timer1 clock = 1MHz)
  	TMR1H  = TMR1L = 0;   // reset Timer1
	ECHO_PIN = a;
	TRIGGER_PIN = b;
	pinMode(ECHO_PIN, INPUT);
}

__bit wait_sensor()
{
  uint16_t i = 0;
  TMR1H  = TMR1L = 0;   // reset Timer1
  TMR1ON = 1;           // enable Timer1 module
  while(!digitalRead(ECHO_PIN) && (i < 1000))
    i = ( TMR1H << 8 ) | TMR1L;   // read Timer1 and store its value in i
 
  if(i >= 1000)
    return 0;
 
  else
    return 1;
}
 
__bit get_distance(uint16_t *ticks)
{
  *ticks = 0;
  TMR1H  = TMR1L = 0;     // reset Timer1
 
  while( digitalRead(ECHO_PIN) && (*ticks < 23200) )
    *ticks = ( TMR1H << 8 ) | TMR1L;    // read Timer1 value
 
  TMR1ON = 0;   // disable Timer1 module
 
  if (*ticks >= 23200)
    return 1;
 
  else
    return 0;
}

float getDistanceCM(){
	// send 10us pulse to HC-SR04 Trigger pin
    digitalWrite(TRIGGER_PIN, LOW);   // make sure trigger pin is low
    __delay_us(2);     // wait 2 us
    digitalWrite(TRIGGER_PIN, HIGH);    // now generate the 10 us pulse
    __delay_us(10);    // wait 10 us
    digitalWrite(TRIGGER_PIN, LOW); 
 
    // read pulse comes from HC-SR04 Echo pin
    if (wait_sensor())
    {    // if there is a response from the sensor
 
      uint16_t distance;
 
      if(get_distance(&distance))
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