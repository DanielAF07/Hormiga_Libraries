#include "system.h"
#include "KeyPad.h"

int colsPin[4] = {12, 11, 10, 9}; // 1, 2, 3, 4
int rowsPin[4] = {22, 21, 20, 19}; // A, B, C, D

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
    keypad = newKeypad(colsPin, rowsPin, keypadTemplate);
}

void loop() {
    char input = readKeypad(keypad);
    if(input == '1') digitalWrite(13, HIGH);
    if(input == '=') digitalWrite(13, LOW);
}