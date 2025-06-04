#include <stdio.h>
#include <string.h>

struct carro
{
    char modelo[30];
    int ano;
    float preco;
};

int main()
{
    struct carro carros[2];

    // Preenchendo os dados dos 2 carros
    for (int i = 0; i < 2; i++)
    {
        printf("Digite o modelo do carro %d:\n", i + 1);
        fgets(carros[i].modelo, sizeof(carros[i].modelo), stdin);
        carros[i].modelo[strcspn(carros[i].modelo, "\n")] = 0; // Remove o '\n'

        printf("Digite o ano do carro %d:\n", i + 1);
        scanf("%d", &carros[i].ano);

        printf("Digite o preco do carro %d:\n", i + 1);
        scanf("%f", &carros[i].preco);

        getchar(); // Limpa o buffer do teclado após ler o float
    }

    // Exibindo os dados dos 2 carros
    printf("\nDados dos carros:\n");
    printf("Modelo\t\tAno\tPreco\n");

    for (int i = 0; i < 2; i++)
    {
        printf("%-12s\t%d\tR$%.2f\n", carros[i].modelo, carros[i].ano, carros[i].preco);
    }
    return 0;
}