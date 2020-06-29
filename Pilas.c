#include "Pilas.h"
#include <malloc.h>
#include <string.h>

void InicPila(Pila *ApPila)
{
     *ApPila = NULL;
}
int Push(Pila *ApPila, TipDatPila Inf)
{
    Nodo *NodoNuevo;
    NodoNuevo = CrearNodo(Inf);
    if(!NodoNuevo)
        return 0;
    NodoNuevo->ApSig = *ApPila;
    *ApPila = NodoNuevo;
    return 1;
}
int Pop(Pila *ApPila, TipDatPila *ApInf)
{
    Nodo *ApTemp;
    if(PilaVacia(*ApPila))
       return 0;
    ApTemp = *ApPila;
    *ApInf = ApTemp->Info;
    *ApPila = ApTemp->ApSig;
    free(ApTemp);
    return 1;
}
int VerTope(Pila P, TipDatPila *ApInf)
{
    if(PilaVacia(P))
       return 0;
    *ApInf = P->Info;
    return 1;
}
int PilaVacia(Pila P)
{
    if(P == NULL)
         return 1;
    return 0;
}
int NumElem(Pila P)
{
    int i;
    for(i=0; P!=NULL;P = P->ApSig);
             i++;
    return i;
}
        
Nodo *CrearNodo(TipDatPila Inf)
{
     Nodo *NodoNuevo;
     NodoNuevo = (Nodo *)malloc(sizeof(Nodo));
     if(NodoNuevo!=NULL)
     {
         if(Inf.CveDato == CADENA)
         {
             NodoNuevo->Info.Dato.Cadena = (char *) malloc(strlen (Inf.Dato.Cadena)+1);
             strcpy (NodoNuevo->Info.Dato.Cadena,Inf.Dato.Cadena);         
             NodoNuevo->Info.CveDato = CADENA;  
         }
         else
             NodoNuevo->Info = Inf;
     }
     return NodoNuevo;
}
