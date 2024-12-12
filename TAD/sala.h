#ifndef SALA_H
#define SALA_H
#include "aluno.h"

#define MAX_ALUNOS 100 
#define MAX_NOTAS_AVALIACAO 5

typedef struct {
    Aluno vetor_alunos[MAX_ALUNOS];
    int numAlunos;
    int notas[MAX_NOTAS_AVALIACAO];
} Sala;

Sala *criaSala();
void adicionaAluno(Sala *sala, Aluno *aluno);
void adicionaAvaliacao(Sala *sala);
int numAprovados(Sala *sala, int conceito);
int numAvaliacoesPendentes(Sala *sala);
void printMediaSala(Sala *sala);

#endif
