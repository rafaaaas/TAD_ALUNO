#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "sala.h"


Sala *criaSala(){
    Sala *sala = (Sala *)malloc(sizeof(Sala));
    if (sala == NULL) {
        printf("Erro ao alocar memoria para a sala!\n");
        exit(1);  // Encerra o programa caso a alocação falhe
    }
    sala->numAlunos = 0;
    return sala;
}


void adicionaAluno(Sala *sala, Aluno *aluno) {
    if (sala->numAlunos < MAX_ALUNOS) {
        sala->vetor_alunos[sala->numAlunos] = *aluno;
        sala->numAlunos++;
    } else {
        printf("Número de alunos excedido!\n");
    }
}
void adicionaAvaliacao(Sala *sala){
    float nota = 0;
    for (int i = 0; i < sala->numAlunos; i++){
        printf("Digite a nota do aluno %s: \n", sala->vetor_alunos[i].nome);
        scanf("%f", &nota);
        adicionaNota(&sala->vetor_alunos[i], nota);
    }
}

int numAprovados(Sala *sala, int conceito) {
    int aprovados = 0;
    for (int i = 0; i < sala->numAlunos; i++) {
        if (mediaAluno(&sala->vetor_alunos[i]) >= conceito) {
            aprovados++;
        }
    }
    return aprovados;
}

int numAvaliacoesPendentes(Sala *sala) {
    int pendentes = 0;
    for (int i = 0; i < sala->numAlunos; i++) {
        for (int j = 0; j < sala->vetor_alunos[i].numNotas; j++) {
            if (sala->vetor_alunos[i].notas[j] == -1) {
                pendentes++;
            }
        }
    }
    return pendentes;
}

void printMediaSala(Sala *sala){
    float media;
    for (int i = 0; i < sala->numAlunos; i++){
        media = mediaAluno(sala->vetor_alunos[i].notas); 
        printf("Media do aluno %s: %f\n", sala->vetor_alunos[i].nome, media); 
            
    }
}
