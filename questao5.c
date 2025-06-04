#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    APROVADO = 1,
    TRANCADO,
    REPROVADO
} Status;

typedef struct
{
    char nome[50];
    unsigned int cod_disciplina;
    Status situacao;
} Aluno;

void exibir_status(const Aluno *aluno)
{
    printf("Nome: %s\n", aluno->nome);
    printf("Codigo da Disciplina: %u\n", aluno->cod_disciplina);
    printf("Situacao: ");
    switch (aluno->situacao)
    {
    case APROVADO:
        printf("Aprovado\n");
        break;
    case TRANCADO:
        printf("Trancado\n");
        break;
    case REPROVADO:
        printf("Reprovado\n");
        break;
    default:
        printf("Situacao desconhecida\n");
    }
}

int main(){
    int n;
    char buffer[100];

    printf("Digite o numero de alunos:\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &n);

    Aluno *alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL)
    {
        fprintf(stderr, "Erro ao alocar memoria para os alunos.\n");
        return 1;
    }

    // Leitura dos dados de todos os alunos
    for (int i = 0; i < n; i++)
    {
        printf("\nAluno %d:\n", i + 1);

        printf("Digite o nome do aluno:\n");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Digite o codigo da disciplina:\n");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%u", &alunos[i].cod_disciplina);

        printf("Digite a situacao do aluno (1 - Aprovado, 2 - Trancado, 3 - Reprovado):\n");
        fgets(buffer, sizeof(buffer), stdin);
        int situacao;
        sscanf(buffer, "%d", &situacao);
        if (situacao < 1 || situacao > 3)
        {
            fprintf(stderr, "Situacao invalida. Usando 'Reprovado' como padrao.\n");
            alunos[i].situacao = REPROVADO;
        }
        else
        {
            alunos[i].situacao = (Status)situacao;
        }
    }

    // Exibe os dados de todos os alunos
    printf("\n--- Dados dos alunos cadastrados ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nAluno %d:\n", i + 1);
        exibir_status(&alunos[i]);
    }

free(alunos);
return 0;
}