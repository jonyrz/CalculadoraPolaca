#include <stdio.h>
#include <stdlib.h>
#include "InfPost.h"


int main() {
    int Result;   
    char ExpInfija[100], ExpPostfija[100];
    //textbackground(0);
    printf("Calculadora Maizoro\n\n");
    printf("Introduzca la Expresion:\n");
    gets(ExpInfija);
    printf("\n");
    
    ConvPostfijo(ExpInfija, ExpPostfija);
    
    Result = EvalExpresion(ExpInfija);
    
    printf("Expresion Postfija:%s\n\n",ExpPostfija);
                                                                                                                                                                                                                                        
    printf("\nResultado=\n\t\t%d\n\n",Result);
    
    system("PAUSE");	
    return 1;
}
