#include "freq_str.h"

void frequencia_string(const char *str, const char *texto, int *qtd)
{
  int letra = 0, strLen = 0, textWordLen = 0, equalsCounter = 0;
  *qtd = 0;

  while (str[strLen] != '\0')
  {
    strLen++;
  }

  letra = 0;
  while (texto[letra] != '\0')
  {
    if (texto[letra] == str[0] || texto[letra] + 32 != str[0] || texto[letra] - 32 != str[0])
    {
      for (int i = 0; i < strLen; i++)
      {
        equalsCounter = 1;
        if (texto[letra + i] != str[i] && texto[letra + i] + 32 != str[i] && texto[letra + i] - 32 != str[i])
        {
          equalsCounter = 0;
          break;
        }
      }
      *qtd = *qtd + equalsCounter;
    }
    letra++;
  }
}