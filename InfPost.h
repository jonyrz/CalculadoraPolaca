int ConvPostfijo(char *ExpInf, char *ExpPost);
/*
La función Precedencia regresa:
              1:  Si CveOperLeido > CveOperPila
              0:  Si CveOperLeido <= CveOperPila
*/
int Precedencia(int CveOperLeido, int CveOperPila);
void CadenaOperador(int CveOper, char *CadOperador);
float EvalExpresion(char *ExpInfija);
