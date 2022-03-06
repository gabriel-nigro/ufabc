#include "vetor.h"
#include <stdlib.h>

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido)
{
  int i = 0, index = 0;
  while (i < n_compactado)
  {
    for (int j = 0; j < vetor[i + 1]; j++)
    {
      index++;
    }
    i = i + 2;
  }
  *n_expandido = index;
  int *n_expandido2 = malloc(sizeof(int) * (index + 1));
  int x = 0, index2 = 0;
  while (x < n_compactado)
  {
    for (int y = 0; y < vetor[x + 1]; y++)
    {
      n_expandido2[index2] = vetor[x];
      index2++;
    }
    x = x + 2;
  }

  return n_expandido2;
}