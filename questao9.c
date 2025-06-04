#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char pais[50];
    char continente[50];
} Local;

int main()
{
    int n;
    char buffer[100];

    printf("Quantos locais deseja visitar nas ferias?\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &n);

    Local *locais = (Local *)malloc(n * sizeof(Local));
    if (locais == NULL)
    {
        fprintf(stderr, "Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nLocal %d:\n", i + 1);

        printf("Nome:\n");
        fgets(locais[i].nome, sizeof(locais[i].nome), stdin);
        locais[i].nome[strcspn(locais[i].nome, "\n")] = 0;

        printf("Pais:\n");
        fgets(locais[i].pais, sizeof(locais[i].pais), stdin);
        locais[i].pais[strcspn(locais[i].pais, "\n")] = 0;

        printf("Continente:\n");
        fgets(locais[i].continente, sizeof(locais[i].continente), stdin);
        locais[i].continente[strcspn(locais[i].continente, "\n")] = 0;
    }
    printf("\nLocais escolhidos:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Local %d:\n", i + 1);
        printf("Nome: %s\n", locais[i].nome);
        printf("Pais: %s\n", locais[i].pais);
        printf("Continente: %s\n", locais[i].continente);
    }

    free(locais);
    return 0;
}