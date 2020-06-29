#define ENTERO  5
#define FLOAT  10
#define CHAR   15
#define CADENA 20


typedef union
{
        int Entero;
        float Flotante;
        char Caracter;
        char *Cadena;
} TipDato;

typedef struct
{ 
        TipDato Dato;
        int    CveDato;
} TipDatPila;
        
typedef struct Nodo
{
        TipDatPila Info;
        struct Nodo *ApSig;
} Nodo;

typedef Nodo *Pila;

void InicPila(Pila *ApPila);
int Push(Pila *ApPila, TipDatPila Inf);
int Pop(Pila *ApPila, TipDatPila *ApInf);
int VerTope(Pila P, TipDatPila *ApInf);
int PilaVacia(Pila P);
int NumElem(Pila P);
Nodo *CrearNodo(TipDatPila Inf);
        
