/* 
 * File:   KeyPad.h
 * Author: DanielAF07
 *
 * Created on 08 de julio de 2020
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

typedef struct _Keypad{
    int cols[4];
    int rows[4];
    char template[4][4];
} Keypad;

Keypad newKeypad(int col[4], int row[4], char template[4][4]); // Pins Columnas, Pins Filas, Template del teclado
char readKeypad(Keypad keyp); // Retorna char del boton presionado

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD_H */

