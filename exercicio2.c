#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM 5
#define NOTAS 2

struct aluno {
    char nome[250];
    char dataDeNascimento[250];
    int notas[NOTAS];
    float media;
};

float calcularMedia(struct aluno *verificarAlunoMedia, int alunoIndex)
{
    int j;
    float somaNotas = 0;
    float media;

    for (j = 0; j < NOTAS; j++) {
        somaNotas += verificarAlunoMedia[alunoIndex].notas[j];
    }
    media = somaNotas / NOTAS;
    verificarAlunoMedia[alunoIndex].media = media;
    
    return media;
}


void situacao (float media) {
    if (media >= 7) {
        printf ("Aprovado\n");
    }
    else {
        printf("Reprovado\n");
    }
}

int main () {

    struct aluno verificarAlunoMedia[TAM];
    int i, j;

    for (i = 0; i < TAM; i++) {
        printf ("Digite o nome do %dº aluno: \n", i + 1);
        gets (verificarAlunoMedia[i].nome);
        printf ("Digite a data de Nascimento do %dº aluno: \n", i + 1);
        gets (verificarAlunoMedia[i].dataDeNascimento);
        for (j = 0; j < NOTAS; j++) {
            printf ("Digite a %dº Nota do %d Aluno: \n", j + 1, i + 1);
            scanf ("%d", &verificarAlunoMedia[i].notas[j]);
        }
        fflush(stdin);
        verificarAlunoMedia[i].media = calcularMedia(verificarAlunoMedia, i);
        printf("Média: %.2f\n", verificarAlunoMedia[i].media);

        situacao(verificarAlunoMedia[i].media);
    } 
}