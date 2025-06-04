#include <stdio.h>
#include <stdlib.h>

// Define a estrutura balão
struct balao {
    char marca[30];
    float diametro;
    int modelo;
};

int main() {
    // Alocação dinânica para balão
    struct balao *b = (struct balao *)malloc(sizeof(struct balao));
    if (b == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1; // Retorna erro se a alocação falhar
    }

    char buffer[100];

    printf("Digite a marca do balao:\n");
    fgets(b->marca, sizeof(b->marca), stdin); // Lê a marca do balão

    printf("Digite o diâmetro do balao:\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &b->diametro); // Lê o diâmetro do balão

    printf("Digite o modelo do balao:\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &b->modelo); // Lê o modelo do balão

    printf("\nDados do balao:\n");
    printf("Marca: %s", b->marca); // Exibe a marca do balão
    printf("Diametro: %.2f\n", b->diametro); // Exibe o diâmetro do balão   
    printf("Modelo: %d\n", b->modelo); // Exibe o modelo do balão

    free(b); // Libera a memória alocada para o balão
    return 0; 
}