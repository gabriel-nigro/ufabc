#include "ordenacao.h"

int ordemLexicografica(const char *a, const char *b)
{
  while (*a && *a == *b)
  {
    ++a;
    ++b;
  }
  return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
}

int verificar_ordenacao(DiscoVoador *discos, int n_discos)
{

  // Verifica se esta em ordem crescente ou decrescente pela autonomia
  int verificaCrescente = 1, autonomiaCrescente = 0, verificaDecrescente = 1, autonomiaDecrescente = 0, i = 0, desempate, desempate2;
  while ((verificaCrescente == 1 || verificaDecrescente == 1) && i < n_discos - 1)
  {
    if (discos[i].autonomia < discos[i + 1].autonomia)
      verificaDecrescente = 0;
    if (discos[i].autonomia == discos[i + 1].autonomia)
    {
      desempate = ordemLexicografica(discos[i].planeta, discos[i + 1].planeta);
      if (desempate == 0)
      {
        desempate2 = ordemLexicografica(discos[i].modelo, discos[i + 1].modelo);
        if (desempate2 > 0)
          verificaCrescente = 0;
      }
      else if (desempate > 0)
      {
        verificaCrescente = 0;
      }
    }
    if (discos[i].autonomia > discos[i + 1].autonomia)
      verificaCrescente = 0;
    i++;
  }
  // Setando como "true"
  if (verificaCrescente == 1)
    autonomiaCrescente = 1;
  if (verificaDecrescente == 1)
    autonomiaDecrescente = 1;

  // Verifica se o modelo esta na ordem lexica
  int verificaLexicaCrescente, modeloLexicaCrescente = 0, verificaLexicaDecrescente, modeloLexicaDecrescente = 0, resultado;
  verificaLexicaCrescente = 1;
  verificaLexicaDecrescente = 1;
  i = 0;
  while ((verificaLexicaCrescente == 1 || verificaLexicaDecrescente == 1) && i < n_discos - 1)
  {
    resultado = ordemLexicografica(discos[i].modelo, discos[i + 1].modelo);
    if (resultado > 0)
      verificaLexicaCrescente = 0;
    if (resultado < 0)
      verificaLexicaDecrescente = 0;
    i++;
  }

  // setando como "true"
  if (verificaLexicaCrescente == 1)
    modeloLexicaCrescente = 1;
  if (verificaLexicaDecrescente == 1)
    modeloLexicaDecrescente = 1;

  // Verifica se o planeta esta na ordem lexica
  int planetaLexicaCrescente = 0, planetaLexicaDecrescente = 0;
  verificaLexicaCrescente = 1;
  verificaLexicaDecrescente = 1;
  i = 0;
  while ((verificaLexicaCrescente == 1 || verificaLexicaDecrescente == 1) && i < n_discos - 1)
  {
    resultado = ordemLexicografica(discos[i].planeta, discos[i + 1].planeta);
    if (resultado > 0)
      verificaLexicaCrescente = 0;
    if (resultado < 0)
      verificaLexicaDecrescente = 0;
    i++;
  }

  // setando como "true"
  if (verificaLexicaCrescente == 1)
    planetaLexicaCrescente = 1;
  if (verificaLexicaDecrescente == 1)
    planetaLexicaDecrescente = 1;

  if (modeloLexicaCrescente == 1)
  {
    return 1;
  }
  else if (modeloLexicaDecrescente == 1)
  {
    return 2;
  }
  else if (planetaLexicaCrescente == 1)
  {
    return 3;
  }
  else if (autonomiaCrescente == 1)
  {
    return 4;
  }
  else
  {
    return 0;
  }
}