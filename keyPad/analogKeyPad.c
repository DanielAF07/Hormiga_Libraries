#include "system.h"
#include "KeyPad.h"

int analogValues[4][4] = { // Template de Valores Analogos. 
    {679, 505, 477, 446},
    {639, 407, 367, 322},
    {587, 263, 202, 130},
    {558, 170, 93, 0}
};


float normalize(Keypad keypad, int value){ // PRIVATE
    for(int i = 0; i < 4 ; i++){
        for(int j = 0; j < 4 ; j++){
            if(value > analogValues[i][j] - keypad.tolerance && value < analogValues[i][j] + keypad.tolerance){
                return analogValues[i][j];
            }
        }
    }
    return 1023;
}

char readAnalog(Keypad keypad){
    int val = analogRead(keypad.pin);
    val = normalize(keypad, val);

    for(int i = 0; i < 4 ; i++){
        for(int j = 0; j < 4 ; j++){
            if(val == analogValues[i][j]){
                return keypad.template[i][j];
            }
        }
    }
    return NO_KEY;
}