#include "system.h"
#include "MathOp.h"

float suma(float a, float b){ // SUMAR DOS NUMEROS (A + B)
    float resultado;
    resultado = a + b;
    return resultado;
}

float resta(float a, float b){ // RESTAR DOS NUMEROS (A - B)
    float resultado;
    resultado = a - b;
    return resultado;
}

float multi(float a, float b){ // MULTIPLICAR DOS NUMEROS (A x B)
    float resultado = 0;
	for(int i = 0; i < a; i++){
        resultado += b;
    }
    return resultado;
}

float div(float dividendo, float divisor){ // Dividir DOS NUMEROS (A / B)
    float resultado2;
    while(1){
        if(dividendo >= divisor){
            resultado2++;
            dividendo -= divisor;
        }
        else {
            break;
        }
    }
    return resultado2;
    /*while(1){
        residuo = dividendo;
        int t = .1;
        if(residuo >= divisor*.5){
            
        }
        
    }*/
}

float resid(float dividendo, float divisor){ // Dividir DOS NUMEROS (A / B)
    float resultado2;
    while(1){
        if(dividendo >= divisor){
            resultado2++;
            dividendo -= divisor;
        }
        else {
            break;
        }
    }
    return dividendo;
    /*while(1){
        residuo = dividendo;
        int t = .1;
        if(residuo >= divisor*.5){
            
        }
        
    }*/
}

float potencia(float a, float exponente){ // Potencia de un numero (A^B)
    unsigned int resultado = a;
    for(int i=1 ; i < exponente ; i++)
    {
        resultado =  multi(resultado, a);
    }
    return resultado;
}

float raizC(float a){
    int i = 1;
    
    while(1){
        if(multi(i,i) == a){
            break;
        } else if(multi(i,i) > a){
            i -= 1;
            break;
        }
        i++;
    }
    return i;
}

float derivar(float error, float lastError, float t){
    float resultado = 0;
    resultado = (error - lastError) / t;
    return resultado;
}

float integrar(float error, float t){
    static float lastData;
    float resultado = 0;
    lastData += multi(error, t);
    resultado = lastData;
    return resultado;
}

unsigned int interpolar(float a, float x1, float x2, float y1, float y2){
    unsigned int interpolacion = 0;
    unsigned int m = 0;
    m = (y2 - y1) / (x2 - x1);
    interpolacion = a * m;
    return interpolacion;
}

float mapx(float a, float x1, float x2, float y1, float y2){ //Mapeo a, xmin, xmax, ymin, ymax
    float resultado;
    resultado = (a - x1) * (y2 - y1) / (x2 - x1) + y1; // Formula general
    return resultado;
}