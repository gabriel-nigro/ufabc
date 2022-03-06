#include "qtd_palavras_frase.h"
#include <stdio.h>

void imprimir_qtd_palavras(char texto[])
{
  int letra = 0, qtd_palavras = 1;
  while (texto[letra] != '\0')
  {
    if (texto[letra] == ' ' && texto[letra + 1] != ' ' && texto[letra + 1] != '.')
    {
      qtd_palavras++;
    }

    if (texto[letra] == '.')
    {
      printf("%d", qtd_palavras);
      if (texto[letra + 1] != '\0')
        printf("\n");
      qtd_palavras = 0;
    }

    letra++;
  }
}