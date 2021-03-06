#include "system.h"
#include "KeyPad.h"

int pinKeypad = 0;
int ledPin = 13;
Keypad myKeypad;

char keypadTemplate[4][4] = {
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'C','0','=','+'}
};

void setup() {
    pinMode(ledPin, OUTPUT);
    myKeypad = newAnalogKeypad(pinKeypad, keypadTemplate);
    // setTolerance(myKeypad, 12) // Default = 12. Try < 12 only if your keypad is working bad.
}

void loop() {
    char input = readKeypad(myKeypad);
    if(input == '1') digitalWrite(13, HIGH);
    if(input == '=') digitalWrite(13, LOW);
}
