/* 
 * File:   MathOp.h
 * Author: Daniel Anchondo
 *
 * Created on 20 de junio de 2020, 02:18 AM
 */

#ifndef MATHOP_H
#define	MATHOP_H
float suma(float a, float b);
float resta(float a, float b);
float multi(float a, float b);
float div(float dividendo, float divisor);
float resid(float dividendo, float divisor);
float potencia(float a, float exponente);
float raizC(float a);
float derivar(float error, float lastError, float t);
float integrar(float error, float t);
unsigned int interpolar(float a, float x1, float x2, float y1, float y2);
float mapx(float a, float x1, float x2, float y1, float y2);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MATHOP_H */

