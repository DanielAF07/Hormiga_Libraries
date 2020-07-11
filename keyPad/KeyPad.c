#include "system.h"
#include "KeyPad.h"
#include "digitalKeyPad.h"
#include "analogKeyPad.h"

void copyArray(char templ[4][4], char copiedTemplate[4][4]){ /// Private // Just to copy a 2d Array.
    for(int j = 0; j<4; j++){
        for(int i = 0 ; i<4; i++){
            templ[j][i] = copiedTemplate[j][i];
        }
    }
}

//Array con los 4 pines en las columnas, array con los 4 pines en las filas.
Keypad newKeypad(int col[4], int row[4], char template[4][4]){ // Create a new Digital Keypad. // Array of cols pins, Array of rows pins, 2D array Template
    Keypad newPad;
    copyArray(newPad.template, template);
    for(int i = 0; i<4; i++){
        newPad.cols[i] = col[i];
        newPad.rows[i] = row[i];
    }  
    newPad.type = DIGITAL;
    return newPad;
}

Keypad newAnalogKeypad(int pin, char template[4][4]){ // Create a New analog Keypad
    Keypad newKeypad;
    copyArray(newKeypad.template, template);
    newKeypad.pin = pin;
    newKeypad.tolerance = 12; // 12 Units default
    pinMode(pin, INPUT);
    newKeypad.type = ANALOG;
    return newKeypad;
}

void setTolerance(Keypad keypad, int toler){ // Set tolerance to analogKeypad
    keypad.tolerance = toler;
}

char readKeypad(Keypad keyp){ // Retorna el char del ultimo boton presionado.
    char valu;
    if(keyp.type == DIGITAL){
        valu = readDigital(keyp);
    } 
    else if(keyp.type == ANALOG){
        valu = readAnalog(keyp);
    }
    return valu;
}