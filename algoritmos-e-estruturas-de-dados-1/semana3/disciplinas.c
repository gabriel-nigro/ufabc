#include <stdlib.h>
#include "disciplinas.h"

void insere_ordem(Disciplina *, Disciplina *);
int menor_lex(char *, char *);

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina)
{
  if (curso->ultima_disciplina == NULL)
  {
    curso->ultima_disciplina = nova_disciplina;
    return;
  }

  insere_ordem(curso->ultima_disciplina, nova_disciplina);
}

void insere_ordem(Disciplina *atual, Disciplina *nova)
{
  if (atual->requisito == NULL)
  {
    atual->requisito = nova;
    return;
  }

  if (menor_lex(nova->nome, atual->requisito->nome) == 1)
  {
    insere_ordem(atual->requisito, nova);
  }
  else
  {
    nova->requisito = atual->requisito;
    atual->requisito = nova;
  }
}

int menor_lex(char *nomeA, char *nomeB)
{
  for (;;)
  {
    if (*nomeA < *nomeB)
      return 1;
    if (*nomeA > *nomeB)
      return 0;
    if (*nomeA == '\0' && *nomeB == '\0')
      return 0;
    nomeA++;
    nomeB++;
  }

  return 0;
}