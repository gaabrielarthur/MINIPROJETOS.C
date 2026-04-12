#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define ARQUIVO "contato.txt"
/*
 Faça um programa para gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e
o aniversário (dia e mês), o programa deve permitir:
• inserir contato.
• remover contato.
• pesquisar um contato pelo nome.
• listar todos os contatos.
• listar os contatos cujo nome inicia com uma dada letra.
• imprimir os aniversariantes do mês.
Sempre que o programa for encerrado, os contatos devem ser armazenados em um arquivo binário. Quando o
programa iniciar, os contatos devem ser inicializados com os dados contidos neste arquivo binário.


*/

typedef struct
{
    char nome[30];
    char telefone[12];
    int dia;
    int mes;
} CONTATO;

CONTATO contatos[MAX];
int total = 0;

// ------------------ arquivo ----------------

void salvar()
{
    FILE *p = fopen(ARQUIVO, "wb");
    if (p == NULL)
    {
        printf("ERRO AO SALVAR !\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, p);
    fwrite(contatos, sizeof(CONTATO), total, p);

    fclose(p);
}

void carregar()
{
    FILE *p;
    p = fopen(ARQUIVO, "rb");
    if (p == NULL)
    {
        printf("ERRO AO DIGITAR NO LER O ARQUIVO\n");
        return;
    }
    fread(&total, sizeof(int), 1, p);
    fread(contatos, sizeof(CONTATO), total, p);

    fclose(p);
}
//------------------- funçôes-----------------

// inserir contato
void inserir()
{
    if (total >= MAX)
    {
        printf("\nAGENDA CHEIA,TENTE NOVAMENTE MAIS TARDE...");
    }
    printf("\nDigite seu nome: ");
    getchar();
    scanf("%[^\n]", &contatos[total].nome);

    printf("\nNUMERO DE TELEFONE: ");
    scanf("%s", contatos[total].telefone);

    printf("DIA QUE NASCEU: ");
    scanf("%d", &contatos[total].dia);

    printf("\nMES QUE NASCEU: ");
    scanf("%d", &contatos[total].mes);

    total++;
    printf("\nContato foi adicionado");
}

// lista contatos

void listar()
{
    for (int i = 0; i < total; i++)
    {
        printf("\nNOME: %s", contatos[i].nome);
        printf("\nTELEFONE: %s", contatos[i].telefone);
        printf("\nDIA QUE NASCEU: %d", contatos[i].dia);
        printf("\nMES QUE NASCEU: %d", contatos[i].mes);
    }
}

// buscar contato
void buscar()
{
    char nome[50];
    printf("\nDigite o nome: ");
    getchar();
    scanf("%[^\n]", &nome);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
            printf("\nNOME ENCONTRADO !");
            printf("\nTELEFONE: %s", contatos[i].telefone);
            printf("\nANIVERSARIO: %02d/%02d\n", contatos[i].dia, contatos[i].mes);
        }
    }
    printf("\ncontato encontrado");
}

// remover contato
void remover()
{
    char nome[50];
    printf("Digite o nome que deseja recomver: ");
    getchar();
    scanf("%[^\n]", &nome);
    for (int i = 0; i < total; i++)
    {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
            for (int j = i; j < total - 1; j++)
            {
                contatos[j] = contatos[j + 1];
            }
            total--;
            printf("Removido!\n");
            return;
        }
    }
}
// listar por letra
void listar_letra()
{
    char letra;
    printf("Digite a letra: ");
    getchar();
    scanf("%c", &letra);

    for (int i = 0; i < total; i++)
    {
        if (contatos[i].nome[0] == letra)
        {
            printf("\n%s - %s", contatos[i].nome, contatos[i].telefone);
        }
    }
}

// mes aniversario

void aniversariantes()
{
    int mes;
    printf("Digite o mes: ");
    scanf("%d", &mes);

    for (int i = 0; i < total; i++)
    {
        if (contatos[i].mes == mes)
        {
            printf("\n%s - %02d/%02d", contatos[i].nome, contatos[i].dia, contatos[i].mes);
        }
    }
}
int main()
{
    int op;
    carregar();
    do
    {
        printf("\n\n--- AGENDA ---\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("4 - Listar todos\n");
        printf("5 - Listar por letra\n");
        printf("6 - Aniversariantes do mes\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            inserir();
            break;
        case 2:
            remover();
            break;
        case 3:
            buscar();
            break;
        case 4:
            listar();
            break;
        case 5:
            listar_letra();
            break;
        case 6:
            aniversariantes();
            break;
        case 0:
            salvar();
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}