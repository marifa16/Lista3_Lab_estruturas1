#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL)
    {
        fprintf(stderr, "Erro ao alocar memoria.\n");
        return 1;
    }

    *p = 100;
    printf("Valor armazenado: %d\n", *p);

    printf("Digite um novo valor:\n");
    scanf("%d", p);

    printf("Novo valor armazenado: %d\n", *p);

    free(p);
    return 0;
}