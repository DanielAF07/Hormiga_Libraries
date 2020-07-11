/* 
 * File:   KeyPad.h
 * Author: DanielAF07
 *
 * Created on 08 de julio de 2020
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#define HIGH 1
#define LOW 0

#define DIGITAL 1
#define ANALOG 2

#define NO_KEY 0

typedef struct _Keypad{
    char template[4][4];
    int type;
    // IF Digital
    int cols[4];
    int rows[4];
    // IF Analog
    int tolerance;
    int pin;
} Keypad;

Keypad newKeypad(int col[4], int row[4], char template[4][4]); // Register a new Digital Keypad.
Keypad newAnalogKeypad(int pin, char _template[4][4]); // Register a new Analog Keypad.
void setTolerance(Keypad keypad, int toler); // Set tolerance for analogKeypad (Only if buttons are not responding correctly)
char readKeypad(Keypad keyp); // Return the button that are you pressing.

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD_H */

