#include <string.h>
#include <stdlib.h>
#include "InfPost.h"
#include "Pilas.h"
#include "Scanner.h"
#include <math.h>
#include <stdio.h>

int ConvPostfijo(char *ExpInf, char *ExpPost)
{
 int band, band2;
 int CveElemLeido;
 int CveOperPila;
 char Elemento[21];
 char CadOper[5];
 Scanner Scan1;
 Pila P;
 TipDatPila Inf;
 InicPila(&P);
 InicScanner(&Scan1, ExpInf);
 ExpPost[0]='\0';
 band =1;
 while(band)
 {
    CveElemLeido=ObtenerElem(&Scan1,Elemento);
    if(CveElemLeido==FIN)
    {
       band = 0;
       continue;
    }
    if(CveElemLeido == NUMERO || CveElemLeido == VAR_X)
    {
       strcat(ExpPost,Elemento);
       strcat(ExpPost," ");
       continue;
    }
    if(CveElemLeido == ERROR)
       return 0;
    if(CveElemLeido == PAR_I || PilaVacia(P))
    {
       Inf.Dato.Flotante = CveElemLeido;
       Inf.CveDato = FLOAT;
       Push(&P, Inf);
       continue;             
    }
    if(CveElemLeido ==PAR_D)
    {
       band2=1;
       while(band2)
       {
                   
           if(PilaVacia(P))
               return 0;
           Pop(&P,&Inf);
           if(Inf.Dato.Flotante==PAR_I)
           {
              
               band2=0;
               continue;
           }
           CadenaOperador(Inf.Dato.Flotante,CadOper);        
           strcat(ExpPost,CadOper);
           strcat(ExpPost," ");
       }             
       continue;             
    }
    VerTope(P, &Inf);
    CveOperPila = Inf.Dato.Entero;
    if(CveOperPila==PAR_I)
    {
       Inf.Dato.Entero = CveElemLeido;
       Inf.CveDato = ENTERO;
       Push(&P, Inf);
       continue;
                          
    }
    if(Precedencia(CveElemLeido,CveOperPila)==1)
    {
       Inf.Dato.Flotante = CveElemLeido;
       Inf.CveDato = FLOAT;
       Push(&P, Inf);
       continue;                                
    }
 
    while(!PilaVacia(P))
    {
        VerTope(P, &Inf);
        CveOperPila = Inf.Dato.Flotante;
        
       
        if(CveOperPila!=PAR_I && Precedencia(CveElemLeido,CveOperPila)==0)
        {
              Pop(&P,&Inf);   
              CadenaOperador(Inf.Dato.Flotante,CadOper);        
              strcat(ExpPost,CadOper);
              strcat(ExpPost," ");                         
              continue;
        } 
        break;      
    }
    Inf.Dato.Flotante = CveElemLeido;
    Inf.CveDato = FLOAT;
    Push(&P, Inf); 
 }
 while(!PilaVacia(P))
 {
     Pop(&P,&Inf);   
     CadenaOperador(Inf.Dato.Flotante,CadOper);        
     strcat(ExpPost,CadOper);
     strcat(ExpPost," ");                         
 }
 return 1;
}

void CadenaOperador(int CveOperador, char *CadOper)
{
     
     switch(CveOperador)
     {
          case SUMA :
                     strcpy(CadOper,"+");
                     return;
          case RESTA :
                     strcpy(CadOper,"-");
                     return;
          case PRODUCTO :
                     strcpy(CadOper,"*");
                     return;
          case DIVISION :
                     strcpy(CadOper,"/");
                     return;
         case PAR_I :
                     strcpy(CadOper,"(");
                     return;
          case PAR_D :
                     strcpy(CadOper,")");
                     return;
           case POTENCIA :
                     strcpy(CadOper,"^");
                     return;
          
                                        
     }
     strcpy(CadOper,"ERROR");
     return;
}
int Precedencia(int OperLeido, int OperPila)
{
    if(OperLeido==SUMA || OperLeido == RESTA)
            return 0;
    if(OperLeido==PRODUCTO || OperLeido == DIVISION)
    {
       if(OperPila == PRODUCTO || OperPila == DIVISION)
                   return 0;
       if(OperPila == SUMA || OperPila == RESTA)
                   return 1;
    }
    return 0;
}
float EvalExpresion(char *ExpInfija)
{
      char  ExpPost[100];
      int CveElemLeido;
      Scanner Scan1;
      Pila P;
      TipDatPila Inf;
      TipDatPila Inf1;
      TipDatPila Inf2;
      TipDatPila Inf3;
      InicPila(&P);
      char Elemento[25];      
      
      ConvPostfijo(ExpInfija, ExpPost);
      InicScanner(&Scan1, ExpPost);
      
      while(1)
      {
             CveElemLeido=ObtenerElem(&Scan1,Elemento);
             if(CveElemLeido == FIN)
                 break;
             switch(CveElemLeido)
             {
                case NUMERO:
                     Inf.Dato.Flotante = atof(Elemento);
                     Inf.CveDato = FLOAT;
                     Push(&P, Inf);
                     break;
                case SUMA:
                     Inf1.CveDato = FLOAT;
                     Inf2.CveDato = FLOAT;
                     Inf3.CveDato = FLOAT;
                     Pop(&P, &Inf1);
                     Pop(&P, &Inf2);
                     Inf3.Dato.Flotante=Inf2.Dato.Flotante + Inf1.Dato.Flotante;
                     Push(&P, Inf3);
                     break;
                     
                 case RESTA:
                     Inf1.CveDato = FLOAT;
                     Inf2.CveDato = FLOAT;
                     Inf3.CveDato = FLOAT;
                     Pop(&P, &Inf1);
                     Pop(&P, &Inf2);
                     Inf3.Dato.Flotante=Inf2.Dato.Flotante - Inf1.Dato.Flotante;
                     Push(&P, Inf3);
                     break;  
                     
                case PRODUCTO:
                     Inf1.CveDato = FLOAT;
                     Inf2.CveDato = FLOAT;
                     Inf3.CveDato = FLOAT;
                     Pop(&P, &Inf1);
                     Pop(&P, &Inf2);
                     Inf3.Dato.Flotante=Inf2.Dato.Flotante * Inf1.Dato.Flotante;
                     Push(&P, Inf3);
                     break; 
                     
                     case DIVISION:
                     Inf1.CveDato = FLOAT;
                     Inf2.CveDato = FLOAT;
                     Inf3.CveDato = FLOAT;
                     Pop(&P, &Inf1);
                     Pop(&P, &Inf2);
                     Inf3.Dato.Flotante=Inf2.Dato.Flotante / Inf1.Dato.Flotante;
                     if(Inf1.Dato.Flotante==0)
                     {
                     	printf("Error\n");
                     	return ERROR;
					 }
                     Push(&P, Inf3);
                     break;
                     
                     
                     case POTENCIA:
                     Inf1.CveDato = FLOAT;
                     Inf2.CveDato = FLOAT;
                     Inf3.CveDato = FLOAT;
                     Pop(&P, &Inf1);
                     Pop(&P, &Inf2);
                     Inf3.Dato.Flotante=pow(Inf2.Dato.Flotante, Inf1.Dato.Flotante);
                     Push(&P, Inf3);
                     break; 
             }       
      }
       Pop(&P, &Inf1);
        return Inf1.Dato.Flotante;
}
