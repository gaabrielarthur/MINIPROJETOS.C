#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
FAÇA UM PROGRAMA DE CALCULADORA, QUE LEIA DOIS VALORES
E MOSTRE AS OPCOES DE SOMAR,SUBTRAIR.
 APÓS SELECIONAR A OPCAO, O RESULTADO SERA MOSTRADO NA TELA BASEADO EM UM SWITCH.
*/

int main()
{

    float a, b;
    int opcao;

    printf("\nCALCULADORA\n");

    printf("\nDigite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("\nESCOLHA A OPCAO\n");
    printf("OPCAO 1 - SOMA\n");
    printf("OPCAO 2 - SUBTRAI\n");
    printf("OPCAO 3 MULTIPLICAR\n");
    printf("OPCAO 4 - DIVIDIR\n");
    printf("DIGITE AQUI: ");
    scanf("%d", &opcao);

    printf("\n CALCULO EXECUTADO\n\n");
    switch (opcao)
    {
    case 1:
        printf("\nA SOMA DE %.2f + %.2f = %.2f\n", a, b, a + b);
        break;

    case 2:
        printf("\nA SUBTRACAO DE %.2f - %.2f = %.2f\n", a, b, a - b);
        break;
    case 3:
        printf("\nA MUTIPLICACAO DE %.2f x %.2f = %.2f\n", a, b, a * b);
        break;
    case 4:
        printf("\nA DIVISAO DE %.2f / %.2f = %.2f\n", a, b, a / b);

    default:
        printf("\nOPCAO INVALIDA!!!\n");
    }

    return 0;
}