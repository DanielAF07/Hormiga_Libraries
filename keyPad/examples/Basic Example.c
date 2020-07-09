#include "system.h"
#include "KeyPad.h"

int colsPin[4] = {12, 11, 10, 9}; // 1, 2, 3, 4
int rowsPin[4] = {22, 21, 20, 19}; // A, B, C, D

Keypad keypad1;

char keypadTemplate[4][4] = {
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'C','0','=','+'}
};

void setup() {
    keypad1 = newKeypad(colsPin, rowsPin, keypadTemplate);
}

void loop() {
    char input = readKeypad(keypad1);
    if(input == '*') digitalWrite(13, HIGH);
    if(input == '/') digitalWrite(13, LOW);
}