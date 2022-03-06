#include "qtd_digitos.h"

int quantidade_digitos(int numero)
{
  int qtd_digitos = 0;

  if (numero == 0)
  {
    qtd_digitos++;
  }
  else
  {
    while (numero != 0)
    {
      qtd_digitos++;
      numero = numero / 10;
    }
  }
  return qtd_digitos;
}