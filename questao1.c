#include <stdio.h>

int main() {
    int n;
    char buffer[100];

    printf("Digite a quantidade de alunos:\n");
    fgets(buffer, sizeof(buffer), stdin); 
    sscanf(buffer, "%d", &n); // Lê o número de alunos

    float notas[n]; // Declara um vetor de notas com tamanho n

    for (int i = 0; i < n; i++) {
        printf("Digite a nota do aluno %d:\n", i + 1);
        fgets(buffer, sizeof(buffer), stdin); 
        sscanf(buffer, "%f", &notas[i]); // Lê a nota do aluno
    }

    printf("Notas dos alunos:\n");
    for (int i = 0; i < n; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]); // Exibe a nota do aluno
    }
    return 0;
}