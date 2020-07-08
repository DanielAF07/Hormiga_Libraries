#include "system.h"
#include "KeyPad.h"

int colsPin[4] = {12, 11, 10, 9}; // 1, 2, 3, 4
int rowsPin[4] = {22, 21, 20, 19}; // A, B, C, D

char passToOn[5] = {'0', '0', '0', '0', '0'};
char passToOff[5] = {'5', '5', '2', '1', '-'};
char input[5];
int index = 0;
char keyPressed;
int sa;

Keypad keypad1;

int compareArrays(char a[5], char b[5], int n){
    for(int i = 0; i<n; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

void resetInput(){
    index = 0;
}

void setup() {
    pinMode(13, OUTPUT);
    keypad1 = newKeypad(colsPin, rowsPin);
}

void loop() {
    int lastKey = keyPressed;
    keyPressed = readKeypad(keypad1);
    if(keyPressed){
        if(keyPressed != lastKey){
            if(keyPressed == 'C'){
                resetInput();
            }
            else if(keyPressed != 'C'){
                input[index] = keyPressed;
                index++;
            }
            if(index > 4){
                if(compareArrays(input, passToOn, 5)){
                    digitalWrite(13, HIGH);
                }
                else if(compareArrays(input, passToOff, 5)){
                    digitalWrite(13, LOW);
                }
                resetInput();
            }
        }
    }
}

