#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char caractere;
    int valor;
} ASCII;

// Função que aloca memória para um vetor de ASCII
ASCII* cria_ascii(int valor, char caractere) {
    ASCII* ascii = (ASCII*)malloc(sizeof(ASCII));
    if (ascii == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    ascii->valor = valor;
    ascii->caractere = caractere;
    return ascii;
} 

int main() {
    int valor;
    char caractere;
    char buffer[100];

    printf("Digite um caractere:\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &caractere);

    printf("Digite um valor inteiro:\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &valor);

    ASCII* ascii = cria_ascii(valor, caractere);

    if (ascii != NULL) {
        printf("Caractere: %c\n", ascii->caractere);
        printf("Valor: %d\n", ascii->valor);
        free(ascii); // Libera a memória alocada
    } else {
        printf("Erro ao criar ASCII.\n");
    }
    return 0;
}