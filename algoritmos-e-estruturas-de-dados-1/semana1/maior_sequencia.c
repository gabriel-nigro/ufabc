#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int v[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
  }

  int sequencia = 1, sequenciaAnterior = 0, maiorSequencia[n], primeiroElemento = 0, primeiroElementoAnterior = 0;
  for (int j = 0; j < n - 1; j++)
  {
    if (v[j] < v[j + 1])
    {
      sequencia++;
      if (sequencia == 2)
      {
        primeiroElemento = j;
      }
      if (sequencia > sequenciaAnterior)
      {
        sequenciaAnterior = sequencia;
        primeiroElementoAnterior = primeiroElemento;
      }
    }
    else
    {
      sequencia = 1;
    }
  }
  for (int x = 0; x < sequenciaAnterior; x++)
  {
    printf("%d ", v[primeiroElementoAnterior + x]);
  }
}