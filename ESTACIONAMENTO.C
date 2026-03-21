#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Estrutura para armazenar os dados de cada veículo
typedef struct{
    char placa[8];
    char modelo[20];
    char horario[15];
    time_t entrada;
}informacoes;

int main() {
    informacoes dados[20];
    int vagas = 20;
    int opcao = 0;
    int posicao;
    time_t agora;
    struct tm *infoTempo;
    FILE *estacionamento;
    char buffer[100];

    for(int i = 0; i < 20; i++){
        dados[i].placa[0] = '\0';
    }

    do{
        posicao = -1;

        for(int i = 0; i < 20; i++){
            if(dados[i].placa[0] == '\0'){
                posicao = i;
                break;
            }
        }

        // MENU
        printf("\n========================================\n");
        printf("        SISTEMA DE ESTACIONAMENTO       \n");
        printf("========================================\n");
        printf("1 - Registrar Veiculo\n");
        printf("2 - Retirada de Veiculo\n");
        printf("3 - Encerrar Programa\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if(opcao == 1){

            if(posicao == -1){
                printf("\n[ERRO] Estacionamento cheio!\n");
                continue;
            }

            printf("\n----------------------------------------\n");
            printf("VAGAS DISPONIVEIS: %d\n", vagas);
            printf("----------------------------------------\n");

            printf("\n>>> REGISTRO DE VEICULO <<<\n");

            printf("Modelo: ");
            fgets(dados[posicao].modelo, sizeof(dados[posicao].modelo), stdin);

            printf("Placa: ");
            fgets(dados[posicao].placa, sizeof(dados[posicao].placa), stdin);

            time(&agora);
            infoTempo = localtime(&agora);

            sprintf(dados[posicao].horario,"%02d:%02d:%02d",
            infoTempo->tm_hour,
            infoTempo->tm_min,
            infoTempo->tm_sec);

            time(&dados[posicao].entrada);

            estacionamento = fopen("DADOS.txt", "a");
            fprintf(estacionamento,
            "\nMODELO: %sPLACA: %sHORARIO DE ENTRADA: %s\nVAGA: %d\n",
            dados[posicao].modelo, dados[posicao].placa,
            dados[posicao].horario, posicao + 1);
            fclose(estacionamento);

            printf("\n========================================\n");
            printf("   VEICULO REGISTRADO COM SUCESSO!      \n");
            printf("========================================\n");

            printf("\n=========== DADOS SALVOS ===========\n");

            estacionamento = fopen("DADOS.txt", "r");
            while(fgets(buffer, 100, estacionamento) != NULL){
                printf("%s", buffer);
            }
            fclose(estacionamento);

            vagas--;

        } else if(opcao == 2){

            int vaga;

            printf("\n>>> RETIRADA DE VEICULO <<<\n");
            printf("Digite o numero da vaga: ");
            scanf("%d", &vaga);

            if(vaga > 0 && vaga <= 20){

                if(dados[vaga-1].placa[0] != '\0'){

                    time_t saida;
                    time(&saida);

                    double tempo = difftime(saida, dados[vaga-1].entrada);
                    double minutos = tempo / 60;

                    double blocos = ceil(minutos / 10);
                    double valor = blocos * 5;

                    printf("\n========================================\n");
                    printf("          RESUMO DA COBRANCA           \n");
                    printf("========================================\n");
                    printf("Tempo total: %.0f minutos\n", minutos);
                    printf("Blocos cobrados: %.0f\n", blocos);
                    printf("Valor a pagar: R$ %.2f\n", valor);
                    printf("========================================\n");

                    dados[vaga-1].placa[0] = '\0';
                    vagas++;

                    printf("\n[OK] Veiculo removido com sucesso!\n");

                } else {
                    printf("\n[AVISO] Vaga ja esta vazia!\n");
                }

            } else {
                printf("\n[ERRO] Vaga invalida!\n");
            }
        }

    }while(opcao != 3);

    return 0;
}