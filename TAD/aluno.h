#ifndef ALUNO_H
#define ALUNO_H

#define MAX_NOTAS 3

typedef struct {
    char nome[100];
    int matricula;
    float notas[MAX_NOTAS];
    int numNotas;
} Aluno;

Aluno criaAluno(char *nome, int matricula);
void adicionaNota(Aluno *a, float nota);
float mediaAluno(Aluno *a);

#endif
