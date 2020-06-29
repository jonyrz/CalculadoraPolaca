#include <stdio.h>
#include <stdlib.h>
#include "InfPost.h"
#include <conio.h>

int main() {
    float Result;   
    char ExpInfija[100], ExpPostfija[100];
    printf("\tEXAMEN PRACTICO: CALCULADORA BASICA\n");
    printf("Conversion de Expresion\n\n");
    printf("Introduzca la Expresion Infija:\n");
    gets(ExpInfija);
    printf("\n");
    ConvPostfijo(ExpInfija, ExpPostfija);
    Result = EvalExpresion(ExpInfija);
    printf("Expresion Posfija:%s\n\n",ExpPostfija);                                                                                                                                                                                                                                    
    printf("\nResultado de las opraciones=\n\t\t%.3f\n",Result);
    system("PAUSE");	
    return 1;
}
