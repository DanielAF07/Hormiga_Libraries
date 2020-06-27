/* 
 * File:   carMotors.h
 * Author: Mr. Daniel Anchondo.
 * 
 * CarMotors
 * Just an easy way to control your L298n and l293d with Hormiga877.
 * Created on June 26, 2020.
 */

#ifndef CARMOTORS_H
#define	CARMOTORS_H

#ifdef	__cplusplus
extern "C" {
#endif
                                                                                                                                                 //|   MOTOR A   ||   MOTOR B   |
                                                                                                                                                 //|-------------||-------------|
void CMinit(unsigned int a1, unsigned int a2, unsigned int apwm, unsigned int b1, unsigned int b2, unsigned int bpwm); //INICIAR 2 motores //(IN1, IN2, ENA, IN3, IN4, ENB)
void CMrightInit(unsigned int a1, unsigned int a2, unsigned int apwm);  // INICIAR Motor derecho // (IN1, IN2, EN)
void CMleftInit(unsigned int b1, unsigned int b2, unsigned int bpwm);   // INICIAR Motor izquierdo // (IN1, IN2, EN)

void CMsetSpeed(int speedL, int speedR); // Manejar motores (VelocidadIzquierda, VelocidadDerecha)
void CMstop(void); // Detener Motores
void CMforward(void); // Dar marcha adelante a maxima velocidad
void CMforwardFor(unsigned int ms); // Dar marcha adelante a maxima velocidad por X ms
void CMbackward(void); // Dar marcha atras a maxima velocidad
void CMbackwardFor(unsigned int ms); // Dar marcha atras a maxima velocidad por X ms
int CMleftGet(void); // Retorna velocidad de motor Izq.
int CMrightGet(void);// Retorna velocidad de motor Der.
int CMrightIsMoving(void); // Retorna True/False si el motor derecho se esta moviendo.
int CMleftIsMoving(void);  // Retorna True/False si el motor izquierdo se esta moviendo.
int CMrightDirection(void); // Retorna la direccion en la que se mueve el motor Derecho.
int CMlefttDirection(void); // Retorna la direccion en la que se mueve el motor Izquierdo.
int CMdemo(void);           // Funcion para probar los motores. Ejecuta Adelante, Atras, Izquierda, Derecha y repite.

#ifdef	__cplusplus
}
#endif

#endif	/* CARMOTORS_H */

