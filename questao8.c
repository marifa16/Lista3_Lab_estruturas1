#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Quantos valores deseja guardar?\n");
    scanf("%d", &n);

    int *p = (int *)malloc(n * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Quais valores deseja guardar?\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Valores armazenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}