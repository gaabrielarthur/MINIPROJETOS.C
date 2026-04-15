#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*
 1. Faça um programa que leia uma série de alunos de um arquivo texto passado via linha de comando. Cada
aluno é composto de:
• Nome (até 30 caracteres).
• Semestre (inteiro).
• Rendimento acadêmico (real).
Considere que cada um dos atributos do aluno está em uma linha separada do arquivo. Por fim, leia um inteiro x do
usuário e informe quais os alunos que estão cursando o semestre x.

*/



typedef struct {
    char nome[30];
    int semestre;
    float rendimento;
} Aluno;

int main() {
    FILE *p;
    Aluno alunos[MAX];
    int i = 0, x;

    p = fopen("alunos.txt", "r");

    if (p == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // leitura do arquivo
    while (fscanf(p, " %[^\n]", alunos[i].nome) != EOF) {
        fscanf(p, "%d", &alunos[i].semestre);
        fscanf(p, "%f", &alunos[i].rendimento);
        i++;
    }

    fclose(p);

    // entrada do usuário
    printf("Digite o semestre que deseja buscar: ");
    scanf("%d", &x);

    // mostrar alunos
    printf("\nAlunos do semestre %d:\n", x);

    for (int j = 0; j < i; j++) {
        if (alunos[j].semestre == x) {
            printf("Nome: %s | Rendimento: %.2f\n",
                   alunos[j].nome,
                   alunos[j].rendimento);
        }
    }

    return 0;
}
