#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "Scanner.h" 
#include <math.h>
#include <ctype.h>


void InicScanner(Scanner *ApScanner, char *ApExpresion)
{
    ApScanner->ApCad = (char *)malloc(strlen(ApExpresion)+1);
    strcpy(ApScanner->ApCad,ApExpresion);
    ApScanner->Tamano = strlen(ApExpresion);
    ApScanner->ApPosActual = ApScanner->ApCad;
    return;
}

int  ObtenerElem(Scanner *ApScanner,char *ApElemento)
{
     
    int i;
    char Aux[21];
    while(*(ApScanner->ApPosActual)==' ')
            ApScanner->ApPosActual++;  
     if(*ApScanner->ApPosActual == '\0')
     {
        ApElemento[0]='\0';
        return FIN;
     }
     if(*(ApScanner->ApPosActual)>='0' && *(ApScanner->ApPosActual)<='9')
     {
          i=0;
          while(isdigit(*ApScanner->ApPosActual))
          {
              Aux[i]=*ApScanner->ApPosActual;
              i++;
              ApScanner->ApPosActual++;
          }
          if(*ApScanner->ApPosActual=='.')
          {
              Aux[i++]=*ApScanner->ApPosActual++;
              while(isdigit(*ApScanner->ApPosActual))
              {
                   Aux[i]=*ApScanner->ApPosActual;
                   i++;
                   ApScanner->ApPosActual++;
              }   
          }
          Aux[i]='\0';
          strcpy(ApElemento,Aux);
          return NUMERO;                    
     }
     if(isalpha(*ApScanner->ApPosActual))
     {
          i=0;
          while(isalpha(*ApScanner->ApPosActual))
          {
              Aux[i]=*ApScanner->ApPosActual;
              i++;
              ApScanner->ApPosActual++;
          }
          Aux[i]='\0';
     }
                                         
     switch(*ApScanner->ApPosActual)
     {
         case '+':
                   strcpy(ApElemento,"+");
                   ApScanner->ApPosActual++;
                   return SUMA;
         case '-':
                   strcpy(ApElemento,"-");
                   ApScanner->ApPosActual++;
                   return RESTA;
         case '*':
                   strcpy(ApElemento,"*");
                   ApScanner->ApPosActual++;
                   return PRODUCTO;
         case '/':
                   strcpy(ApElemento,"/");
                   ApScanner->ApPosActual++;
                   return DIVISION;
        case '^': 
                   strcpy(ApElemento,"^");
                   ApScanner->ApPosActual++;
                   return POTENCIA;  
         case 'X':
         case 'x':
                   strcpy(ApElemento,"X");
                   ApScanner->ApPosActual++;
                   return VAR_X;
         case '(':

                   strcpy(ApElemento,"(");
                   ApScanner->ApPosActual++;
                   return PAR_I;

         case ')':
                   strcpy(ApElemento,")");
                   ApScanner->ApPosActual++;
                   return PAR_D;
     }
     ApElemento[0]=*ApScanner->ApPosActual;
     ApElemento[1]='\0';
     ApScanner->ApPosActual++;
     return ERROR;

}

