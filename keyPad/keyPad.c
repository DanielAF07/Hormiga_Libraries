#include "system.h"
#include "keyPad.h"

#define HIGH 1
#define LOW 0

#define INPUT 1
#define OUTPUT 0
                       
//Array con los 4 pines en las columnas, array con los 4 pines en las filas.
Keypad newKeypad(int col[4], int row[4]){ // Registrar los pines que utiliza nuestro keypad utilizando 2 arrays de 4 variables.
    Keypad newPad;
    for(int i = 0; i<4; i++){
        newPad.cols[i] = col[i];
        newPad.rows[i] = row[i];
    }
    newPad.type = 0;
    return newPad;
}

void setPinsMode(int arr[4], int state){//Privada // Poner array de 4 pines en modo especificado
    for(int i = 0; i < 4; i++){
        pinMode(arr[i], state);
    }
}

int dRead(int arr[4]){ //Privada // Leer un array de 4 pines digitales
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

void dWrite(int arr[4], int state){ // Privada // Mandar una señal + o - en un array de 4 pines
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
        if(keyp.type == 0){
            switch(result){
                case 11:
                    return '7';
                break;
                case 21:
                    return '8';
                break;
                case 31:
                    return '9';
                break;
                case 41:
                    return '/';
                break;
                case 12:
                    return '4';
                break;
                case 22:
                    return '5';
                break;
                case 32:
                    return '6';
                break;
                case 42:
                    return '*';
                break;
                case 13:
                    return '1';
                break;
                case 23:
                    return '2';
                break;
                case 33:
                    return '3';
                break;
                case 43:
                    return '-';
                break;
                case 14:
                    return 'C';
                break;
                case 24:
                    return '0';
                break;
                case 34:
                    return '=';
                break;
                case 44:
                    return '+';
                break;
            }
        }
    }
}
