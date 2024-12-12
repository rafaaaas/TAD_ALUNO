#include <stdio.h>
#include "aluno.h"
#include "sala.h"

int main() {
    // Criando alguns alunos
    Aluno aluno1 = criaAluno("Joao", 12345);
    Aluno aluno2 = criaAluno("Maria", 67890);

    //adicionaNota(&aluno1, 7.5);
    //adicionaNota(&aluno1, 8.0);
    //adicionaNota(&aluno1, 6.5);
    
    //adicionaNota(&aluno2, 9.0);
    //adicionaNota(&aluno2, 8.5);

    
    // Criando a sala e adicionando os alunos
    Sala *sala = criaSala();
    adicionaAluno(sala, &aluno1);
    adicionaAluno(sala, &aluno2);

    adicionaAvaliacao(sala);
    adicionaAvaliacao(sala);
    adicionaAvaliacao(sala);

    printf("Media de %s: %.2f\n", aluno1.nome, mediaAluno(&aluno1));
    printf("Media de %s: %.2f\n", aluno2.nome, mediaAluno(&aluno2));

    // Verificando o número de aprovados na sala com conceito 7.0
    int aprovados = numAprovados(sala, 7);  // Remover o '&' aqui
    printf("Numero de aprovados com conceito 7: %d\n", aprovados);
    printMediaSala(sala);

    return 0;
}
