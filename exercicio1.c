#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM 3

struct contato {
    char nome[200];
    char telefone[200];
    char email[200];
};

void verificarNome(struct contato verificarContato[], char *opcao)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(verificarContato[i].nome, opcao) == 0)
        {
            printf("\nTelefone de %s: %s", verificarContato[i].nome, verificarContato[i].telefone);
            return;
        }
    }
    printf("\nContato não encontrado.");
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct contato verificarContato[TAM];

    int i;
    char opcao[200];

    for (i = 0; i < TAM; i++)
    {
        printf("Digite o nome do %dº contato:\n", i + 1);
        gets(verificarContato[i].nome);
        printf("Digite o numero de telefone:\n");
        gets(verificarContato[i].telefone);
        printf("Digite o Email:\n");
        gets(verificarContato[i].email);
    }

    fflush(stdin);
    printf("Digite o nome do contato que deseja buscar: \n");
    gets(opcao);

    verificarNome(verificarContato, opcao);
    return 0;
}