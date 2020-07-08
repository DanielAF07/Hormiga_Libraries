#include "system.h"
#include "KeyPad.h"

int colsPin[4] = {12, 11, 10, 9}; // 1, 2, 3, 4
int rowsPin[4] = {22, 21, 20, 19}; // A, B, C, D

Keypad keypad1;

void setup() {
    pinMode(13, OUTPUT);
    keypad1 = newKeypad(colsPin, rowsPin);
}

void loop() {
    char keyPressed = readKeypad(keypad1);
    if(keyPressed){
        if(keyPressed == '1'){
            digitalWrite(13, HIGH);
        } else {
            digitalWrite(13, LOW);
        }
    }
}
