#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno criaAluno(char *nome, int matricula) {
    Aluno aluno;
    strncpy(aluno.nome, nome, sizeof(aluno.nome) - 1); // Usa o tamanho máximo do nome
    aluno.nome[sizeof(aluno.nome) - 1] = '\0'; // Garante que a string termine com '\0'
    aluno.matricula = matricula;
    aluno.numNotas = 0;

    // Inicializa todas as notas como -1 (indicação de "não atribuída")
    for(int i = 0; i < MAX_NOTAS; i++) {
        aluno.notas[i] = -1;
    }
    
    return aluno;
}

void adicionaNota(Aluno *aluno, float nota) {
    if(aluno->numNotas < MAX_NOTAS) {
        aluno->notas[aluno->numNotas] = nota;
        aluno->numNotas++;
    } else {
        printf("Número máximo de notas do aluno %s excedido!\n", aluno->nome);
    }
}

float mediaAluno(Aluno *aluno) {
    if (aluno->numNotas == 0) {
        return 0.0;
    }

    float media = 0.0;
    for(int i = 0; i < aluno->numNotas; i++) {
        media += aluno->notas[i];
    }
    return media / aluno->numNotas;
}
