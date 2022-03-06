#include "fracoes.h"

Fracao somar(Fracao f1, Fracao f2)
{
  int mdc, numerador, denominador; // Máximo divisor comum

  numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador);
  denominador = f1.denominador * f2.denominador;

  for (int i = 1; i <= numerador && i <= denominador; ++i)
  {
    if (numerador % i == 0 && denominador % i == 0)
    {
      mdc = i;
    }
  }

  Fracao resultado;
  resultado.numerador = numerador / mdc;
  resultado.denominador = denominador / mdc;
  return resultado;
}

Fracao somar_vetor(Fracao f[], int n_fracoes)
{
  long mdc, numerador, denominador; // Máximo divisor comum
  int i;

  numerador = (f[0].numerador * f[1].denominador) + (f[1].numerador * f[0].denominador);
  denominador = f[0].denominador * f[1].denominador;

  for (i = 2; i < n_fracoes; i++)
  {
    numerador = (f[i].numerador * denominador) + (numerador * f[i].denominador);
    denominador = f[i].denominador * denominador;

    for (int i = 1; i <= numerador && i <= denominador; ++i)
    {
      if (numerador % i == 0 && denominador % i == 0)
      {
        mdc = i;
      }
    }
    numerador = numerador / mdc;
    denominador = denominador / mdc;
  }

  Fracao resultado;
  resultado.numerador = numerador;
  resultado.denominador = denominador;
  return resultado;
}

Fracao multiplicar(Fracao f1, Fracao f2)
{
  int mdc, numerador, denominador; // Máximo divisor comum

  numerador = f1.numerador * f2.numerador;
  denominador = f1.denominador * f2.denominador;

  for (int i = 1; i <= numerador && i <= denominador; ++i)
  {
    if (numerador % i == 0 && denominador % i == 0)
    {
      mdc = i;
    }
  }

  Fracao resultado;
  resultado.numerador = numerador / mdc;
  resultado.denominador = denominador / mdc;
  return resultado;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes)
{
  int mdc, numerador, denominador, i; // Máximo divisor comum

  numerador = f[0].numerador * f[1].numerador;
  denominador = f[0].denominador * f[1].denominador;

  for (i = 2; i < n_fracoes; i++)
  {
    numerador = f[i].numerador * numerador;
    denominador = f[i].denominador * denominador;
  }

  for (int i = 1; i <= numerador && i <= denominador; ++i)
  {
    if (numerador % i == 0 && denominador % i == 0)
    {
      mdc = i;
    }
  }

  Fracao resultado;
  resultado.numerador = numerador / mdc;
  resultado.denominador = denominador / mdc;
  return resultado;
}