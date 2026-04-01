#include <stdio.h>
#include <stdlib.h>
#define MAX 5
/*
Desafio 1 — Sistema de Cadastro de Produtos (com struct + funções)

Crie um programa que:

📌 Requisitos:
Use uma struct chamada Produto com:
nome
preço
quantidade
Cadastre até 5 produtos

Crie funções para:
Cadastrar produtos
Mostrar todos os produtos
Calcular o valor total em estoque
Mostre no final:
Lista de produtos
Valor total do estoque

💡 Extra (diferencial):
Mostrar o produto mais caro
Mostrar o produto com maior quantidade
*/
typedef struct
{
    char nome[255];
    float preco;
    int quantidade;
} produto;

// cadastrando o produto
void cadastro(produto p[], int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        printf("\nDigite o NOME do produto %d: ", i + 1);
        scanf(" %[^\n]", &p[i].nome);

        printf("\nDigite o PRECO do produto: ");
        scanf("%f", &p[i].preco);

        printf("\nDigite a quantidade: ");
        scanf("%d", &p[i].quantidade);

        getchar();
    }
}

// imprimindo os cadastros
void imprimi(produto p[], int tamanho)
{
    printf("\n\n===============PRODUTOS CADASTRADOS================\n\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nNOME PRODUTO: %s\n", p[i].nome);
        printf("\nVALOR PRODUTO: %.2f\n", p[i].preco);
        printf("\nQUANTIDADE: %d", p[i].quantidade);
    }
}

// calculando o total
float calculartotal(produto p[], int tamanho)
{
    float total = 0;

    for (int i = 0; i < tamanho; i++)
    {
        total += p[i].preco * p[i].quantidade;
    }

    return total;
}

// produto mais caro
void maiscaro(produto p[], int tamanho)
{
    int indice = 0;
    for (int i = 1; i < tamanho; i++)
    {
        if (p[i].preco > p[indice].preco)
        {
            indice = i;
        }
    }

    printf("\n\n================PRODUTO MAIS CARO=================\n\n");
    printf("\nNOME: %s\n", p[indice].nome);
    printf("\nPRECO: R$%.2f\n", p[indice].preco);
}
// produto com maior quantidade
void maiorquantidade(produto p[], int tamanho)
{
    int indice = 0;
    for (int i = 1; i < tamanho; i++)
    {

        if (p[i].quantidade > p[indice].quantidade)
        {
            indice = i;
        }
    }
    printf("\n\n=====MAIOR QUANTIDADE EM ESTOQUE=====\n\n");
    printf("\nNome: %s\n", p[indice].nome);
    printf("\nQuantidade: %d\n", p[indice].quantidade);
}

int main()
{

    produto p[MAX];

    cadastro(p, MAX);
    imprimi(p, MAX);
    maiscaro(p, MAX);
    maiorquantidade(p, MAX);

    float total = calculartotal(p, MAX);
    printf("\n\n===================VALOR TOTAL EM ESTOQUE========================\n\n");
    printf("\nTOTAL: R$%.2f\n", total);

    return 0;
}