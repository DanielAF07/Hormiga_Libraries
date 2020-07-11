/* 
 * File:   digitalKeypad.h
 * Author: DanielAF07
 *
 * Created on July/2020
 */

#ifndef DIGITALKEYPAD_H
#define	DIGITALKEYPAD_H

void setPinsMode(int arr[4], int state);
void setInput(int arr[4]);
void setOutput(int arr[4]);
int dRead(int arr[4]);
void dWrite(int arr[4], int state);
char readDigital(Keypad keyp);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DIGITALKEYPAD_H */

