#include "qtd_discos.h"
#include <stdlib.h>

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante)
{
  *quantidade_por_fabricante = malloc(sizeof(int) * n_discos);
  int i, modeloA = 0, modeloB = 0, modeloC = 0, modeloD = 0;

  for (i = 0; i < n_discos; i++)
  {
    if (discos[i][7] == 'A')
    {
      modeloA++;
    }
    else if (discos[i][7] == 'B')
    {
      modeloB++;
    }
    else if (discos[i][7] == 'C')
    {
      modeloC++;
    }
    else if (discos[i][7] == 'D')
    {
      modeloD++;
    }
  }

  (*quantidade_por_fabricante)[0] = modeloA;
  (*quantidade_por_fabricante)[1] = modeloB;
  (*quantidade_por_fabricante)[2] = modeloC;
  (*quantidade_por_fabricante)[3] = modeloD;
}