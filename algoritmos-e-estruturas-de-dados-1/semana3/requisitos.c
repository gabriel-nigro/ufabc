#include <stdlib.h>
#include "requisitos.h"

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd)
{
  *qtd = 0;
  Disciplina *resultado;
  resultado = disciplina;
  if (resultado->requisito == NULL)
    return NULL;

  while (resultado->requisito != NULL)
  {
    *qtd = *qtd + 1;
    resultado = resultado->requisito;
  }
  disciplina = resultado;
  return disciplina;
}