/* 
 * File:   HCSR04.h
 * Author: danar
 *
 * Created on 27 de junio de 2020, 02:05 PM
 */

#ifndef HCSR04_H
#define	HCSR04_H
typedef struct _HCSR04{
    int triggerPin;
    int echoPin;
} HCSR04;

HCSR04 HCSR04init(int a, int b);
double getDistanceCM(HCSR04 sensor);
double getDistanceInches(HCSR04 sensor);
double getDistanceFeets(HCSR04 sensor);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* HCSR04_H */

