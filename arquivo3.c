#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
3. Um arquivo JSON (JavaScript Object Notation) é utilizado frequentemente para transmitir dados. Basicamente
trata-se de um arquivo texto no formato “chave”:valor. Faça um programa que, dado um arquivo JSON
passado via parâmetros de linha de comando, interprete-o em um registro em memória. O JSON da questão
tem o seguinte formato, podendo assumir valores diferentes a cada arquivo:
{
"nome": "Epaminondas",
"sobrenome": "da Silva",
"vivo": 1,
"idade": 25,
"endereco": "IFTM"
}
As chaves podem vir em ordem diferente a cada arquivo, então você deverá utilizar o nome delas para identificar
em qual campo do registro os valores devem ser gravados. Após converter um arquivo JSON na sua representação
em registro, o seu programa deverá dar a opção de alterar os dados em memória e sobrescrever o arquivo original.
Referência: https://en.wikipedia.org/wiki/JSON

*/
typedef struct {
    char nome[50];
    char sobrenome[50];
    int vivo;
    int idade;
    char endereco[100];
} Pessoa;

// ----------- LER JSON -----------
void ler_json(char *arquivo, Pessoa *p) {
    FILE *f = fopen(arquivo, "r");
    if (!f) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    char linha[200], chave[50], valor[100];

    while (fgets(linha, sizeof(linha), f)) {

        // tenta ler string
        if (sscanf(linha, " \"%[^\"]\" : \"%[^\"]\"", chave, valor) == 2 ||
            sscanf(linha, " \"%[^\"]\" : %s", chave, valor) == 2) {

            // remove vírgula
            valor[strcspn(valor, ",\n")] = '\0';

            if (strcmp(chave, "nome") == 0)
                strcpy(p->nome, valor);

            else if (strcmp(chave, "sobrenome") == 0)
                strcpy(p->sobrenome, valor);

            else if (strcmp(chave, "vivo") == 0)
                p->vivo = atoi(valor);

            else if (strcmp(chave, "idade") == 0)
                p->idade = atoi(valor);

            else if (strcmp(chave, "endereco") == 0)
                strcpy(p->endereco, valor);
        }
    }

    fclose(f);
}

// ----------- SALVAR JSON -----------
void salvar_json(char *arquivo, Pessoa p) {
    FILE *f = fopen(arquivo, "w");

    fprintf(f, "{\n");
    fprintf(f, "\"nome\": \"%s\",\n", p.nome);
    fprintf(f, "\"sobrenome\": \"%s\",\n", p.sobrenome);
    fprintf(f, "\"vivo\": %d,\n", p.vivo);
    fprintf(f, "\"idade\": %d,\n", p.idade);
    fprintf(f, "\"endereco\": \"%s\"\n", p.endereco);
    fprintf(f, "}\n");

    fclose(f);
}

// ----------- MOSTRAR -----------
void mostrar(Pessoa p) {
    printf("\nNome: %s %s\n", p.nome, p.sobrenome);
    printf("Vivo: %d\n", p.vivo);
    printf("Idade: %d\n", p.idade);
    printf("Endereco: %s\n", p.endereco);
}

// ----------- EDITAR -----------
void editar(Pessoa *p) {
    printf("\nNovo nome: ");
    scanf(" %[^\n]", p->nome);

    printf("Novo sobrenome: ");
    scanf(" %[^\n]", p->sobrenome);

    printf("Vivo (1/0): ");
    scanf("%d", &p->vivo);

    printf("Idade: ");
    scanf("%d", &p->idade);

    printf("Endereco: ");
    scanf(" %[^\n]", p->endereco);
}

// ----------- MAIN -----------
int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Use: %s arquivo.json\n", argv[0]);
        return 1;
    }

    Pessoa p;

    ler_json(argv[1], &p);

    printf("\n--- DADOS ---\n");
    mostrar(p);

    char op;
    printf("\nEditar dados? (s/n): ");
    scanf(" %c", &op);

    if (op == 's') {
        editar(&p);
        salvar_json(argv[1], p);
        printf("\nArquivo atualizado!\n");
    }

    return 0;
}