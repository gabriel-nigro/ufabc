#include "palavra.h"

void substituir_palavra(char *texto, char *palavra1, char *palavra2)
{
  int letra = 0, palavra1Len = 0, palavra2Len = 0, initialIndex, found = 0;

  while (palavra1[palavra1Len] != '\0')
  {
    palavra1Len++;
  }

  while (palavra2[palavra2Len] != '\0')
  {
    palavra2Len++;
  }

  letra = 0;
  while (texto[letra] != '\0')
  {
    if (texto[letra] == palavra1[0] && found == 0)
    {
      for (int i = 0; i < palavra1Len; i++)
      {
        initialIndex = letra;
        found = 1;
        if (texto[letra + i] != palavra1[i])
        {
          found = 0;
          break;
        }
      }
    }
    letra++;
  }
  int lastPartIndex = letra - initialIndex + palavra1Len;
  char lastPart[lastPartIndex];
  for (int j = 0; j < lastPartIndex; j++)
  {
    lastPart[j] = texto[initialIndex + palavra1Len + j];
  }

  for (int x = 0; x < palavra2Len; x++)
  {
    texto[initialIndex + x] = palavra2[x];
  }

  for (int y = 0; y < lastPartIndex; y++)
  {
    texto[initialIndex + palavra2Len + y] = lastPart[y];
  }
  texto[initialIndex + palavra2Len + lastPartIndex + 1] = '\0';
}