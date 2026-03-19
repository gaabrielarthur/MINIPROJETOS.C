#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// SISTEMA DE CAIXA DE UM SUPER MERCADO 
#define MAX 100

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
    float subtotal;
} Produto;

int main() {
    Produto produtos[MAX];
    int i = 0;
    int continuar = 1;
    float total = 0;
    float pagamento, troco;

    FILE *arquivo;

    printf("=== SISTEMA DE CAIXA DE SUPERMERCADO ===\n");

    while (continuar) {

        printf("\nProduto %d\n", i + 1);

        printf("Nome do produto: ");
        scanf(" %[^\n]", produtos[i].nome);

        printf("Preco do produto: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);

        produtos[i].subtotal = produtos[i].preco * produtos[i].quantidade;
        total += produtos[i].subtotal;

        printf("Adicionar outro produto? (1=Sim / 0=Nao): ");
        scanf("%d", &continuar);

        i++;
    }

    printf("\n=== RESUMO DA COMPRA ===\n");

    for(int j = 0; j < i; j++) {
        printf("%s | Preco: %.2f | Quantidade: %d | Subtotal: %.2f\n",
               produtos[j].nome,
               produtos[j].preco,
               produtos[j].quantidade,
               produtos[j].subtotal);
    }

    printf("\nTOTAL: %.2f\n", total);

    printf("\nValor pago pelo cliente: ");
    scanf("%f", &pagamento);

    if(pagamento < total) {
        printf("Pagamento insuficiente!\n");
    } else {
        troco = pagamento - total;
        printf("Troco: %.2f\n", troco);
    }

    arquivo = fopen("compras.txt", "a");

    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "===== NOVA COMPRA =====\n");

    for(int j = 0; j < i; j++) {
        fprintf(arquivo, "%s | %.2f | %d | %.2f\n",
                produtos[j].nome,
                produtos[j].preco,
                produtos[j].quantidade,
                produtos[j].subtotal);
    }

    fprintf(arquivo, "TOTAL: %.2f\n", total);
    fprintf(arquivo, "Pago: %.2f\n", pagamento);
    fprintf(arquivo, "Troco: %.2f\n", troco);
    fprintf(arquivo, "=======================\n\n");

    fclose(arquivo);

    printf("\nCompra salva em compras.txt\n");

    return 0;
}