#include "system.h"
#include "KeyPad.h"

#define HIGH 1
#define LOW 0


void copyArray(char templ[4][4], char copiedTemplate[4][4]){
    for(int j = 0; j<4; j++){
        for(int i = 0 ; i<4; i++){
            templ[j][i] = copiedTemplate[j][i];
        }
    }
}

//Array con los 4 pines en las columnas, array con los 4 pines en las filas.
Keypad newKeypad(int col[4], int row[4], char template[4][4]){ // Registrar los pines que utiliza nuestro keypad utilizando 2 arrays de 4 variables.
    Keypad newPad;
    for(int i = 0; i<4; i++){
        newPad.cols[i] = col[i];
        newPad.rows[i] = row[i];
    }
    copyArray(newPad.template, template);
    return newPad;
}



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
    int enabled = 0;
    int arrValues[4];
    for(int i = 0; i < 4; i++){
        arrValues[i] = digitalRead(arr[i]);
        if(arrValues[i]){
            enabled = i + 1;
        }
    }
    return enabled;
}

void dWrite(int arr[4], int state){ // Privada
    for(int i = 0; i < 4; i++){
        digitalWrite(arr[i], state);
    }
}

char readKeypad(Keypad keyp){ // Retorna el char del ultimo boton presionado.
    //PRIMERO LEE colsPin y DESPUES ROWS
    setPinsMode(keyp.cols, INPUT);
    setPinsMode(keyp.rows, OUTPUT);
    int inputA, inputB;
    dWrite(keyp.rows, HIGH);
    inputA = dRead(keyp.cols);
    if(inputA != 0){
        dWrite(keyp.rows, LOW);
        setPinsMode(keyp.rows, INPUT);
        setPinsMode(keyp.cols, OUTPUT);
        dWrite(keyp.cols, HIGH);
        inputB = dRead(keyp.rows);
    }
    if(inputA != 0 && inputB != 0){
        int result = inputA*10 + inputB;
        switch(result){
            case 11:
                return keyp.template[0][0];
            break;
            case 21:
                return keyp.template[0][1];
            break;
            case 31:
                return keyp.template[0][2];
            break;
            case 41:
                return keyp.template[0][3];
            break;
            case 12:
                return keyp.template[1][0];
            break;
            case 22:
                return keyp.template[1][1];
            break;
            case 32:
                return keyp.template[1][2];
            break;
            case 42:
                return keyp.template[1][3];
            break;
            case 13:
                return keyp.template[2][0];
            break;
            case 23:
                return keyp.template[2][1];
            break;
            case 33:
                return keyp.template[2][2];
            break;
            case 43:
                return keyp.template[2][3];
            break;
            case 14:
                return keyp.template[3][0];
            break;
            case 24:
                return keyp.template[3][1];
            break;
            case 34:
                return keyp.template[3][2];
            break;
            case 44:
                return keyp.template[3][3];
            break;
        }
    }
}
