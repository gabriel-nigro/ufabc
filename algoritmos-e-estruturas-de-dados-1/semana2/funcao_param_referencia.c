#include "funcao_param_referencia.h"

void funcao(int a, int b, int *resultado)
{
  int segundoSomatorio = 0;
  *resultado = 0;
  for (int i = 1; i <= a; i++)
  {
    for (int j = 1; j <= b; j++)
    {
      segundoSomatorio = segundoSomatorio + ((i * j) + 10);
    }
    *resultado = *resultado + ((5 * i) * segundoSomatorio);
    segundoSomatorio = 0;
  }
}