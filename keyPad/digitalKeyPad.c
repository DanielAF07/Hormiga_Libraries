#include "system.h"
#include "KeyPad.h"

#define NONE -1

void setPinsMode(int arr[4], int state){//Privada // Poner array de 4 pines en modo INPUT
    for(int i = 0; i < 4; i++){
        pinMode(arr[i], state);
    }
}

void setInput(int arr[4]){//Privada
    for(int i = 0; i < 4; i++){
        pinMode(arr[i], INPUT);
    }
}

void setOutput(int arr[4]){ //Privada
    for(int i = 0; i < 4; i++){
        pinMode(arr[i], OUTPUT);
    }
}

int dRead(int arr[4]){ //Privada
    int enabled = NONE;
    int arrValues[4];
    for(int i = 0; i < 4; i++){
        arrValues[i] = digitalRead(arr[i]);
        if(arrValues[i]){
            enabled = i;
        }
    }
    return enabled;
}

void dWrite(int arr[4], int state){ // Privada
    for(int i = 0; i < 4; i++){
        digitalWrite(arr[i], state);
    }
}

char readDigital(Keypad keyp){
    setPinsMode(keyp.cols, INPUT);
    setPinsMode(keyp.rows, OUTPUT);
    int inputA, inputB;
    dWrite(keyp.rows, HIGH);
    inputA = dRead(keyp.cols);
    if(inputA != NONE){
        dWrite(keyp.rows, LOW);
        setPinsMode(keyp.rows, INPUT);
        setPinsMode(keyp.cols, OUTPUT);
        dWrite(keyp.cols, HIGH);
        inputB = dRead(keyp.rows);
    }
    if(inputA != NONE && inputB != NONE){
        return keyp.template[inputB][inputA];
    }
    return NO_KEY;
}