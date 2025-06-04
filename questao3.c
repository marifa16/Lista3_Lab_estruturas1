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
    struct carro carros[10] = {
        {"Vectra", 2009, 58000.00},
        {"Polo", 2008, 45000.00},
        {"Opala", 1973, 25000.00},
        {"Corvette", 1962, 150000.00},
        {"Miata", 1990, 30000.00},
        {"Maverick", 1974, 20000.00},
        {"Esplanada", 1970, 15000.00},
        {"Fusca", 1980, 12000.00},
        {"Chevette", 1985, 10000.00},
        {"Alfa Romeo", 1995, 80000.00}};

    printf("Dados dos carros:\n");
    printf("Modelo\t\tAno\tPreco\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%-12s\t%d\tR$%.2f\n", carros[i].modelo, carros[i].ano, carros[i].preco);
    }

    return 0;
}