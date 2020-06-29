#define ERROR       0
#define NUMERO      10
#define VAR_X       12
#define SUMA        15
#define RESTA       20
#define PRODUCTO    25
#define DIVISION    30
#define PAR_I       35
#define PAR_D       40
#define POTENCIA    60
#define FIN         500

typedef struct 
{
    char *ApCad;
    int Tamano;
    char *ApPosActual;
} Scanner;

void InicScanner(Scanner *ApScan, char *ApExpresion);
int  ObtenerElem(Scanner *ApScan,char *ApElemento);
