/* 
 * File:   keyPad.h
 * Author: DanielAF07
 *
 * Created on 08 de julio de 2020
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

typedef struct _Keypad{
    int cols[4];
    int rows[4];
    int type; //Proximamente se agregaran tipos de keypad para hacer corresponder el char que retorna con el layout del keypad.
} Keypad;

Keypad newKeypad(int col[4], int row[4]); // Registrar un nuevo keypad (Es necesario hacerlo con 2 arrays que contengan los pines de las columnas y filas)
char readKeypad(Keypad keyp); // Retorna char del boton presionado

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD_H */

