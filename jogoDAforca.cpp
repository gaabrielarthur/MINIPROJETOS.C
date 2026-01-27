#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

/* ==============================
   Limpa a tela (Windows / Linux)
   ============================== */
void limparTela() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

/* ==============================
   Retorna uma palavra aleatória
   ============================== */
string palavraAleatoria() {
    string palavras[] = {"abacaxi", "manga", "morango"};
    int indice = rand() % 3;
    return palavras[indice];
}

/* ==============================
   Cria a máscara da palavra
   Ex: "manga" → "_____"
   ============================== */
string criarMascara(int tamanho) {
    return string(tamanho, '_');
}

/* ==============================
   Mostra o status do jogo
   ============================== */
void mostrarStatus(string mascara,
                   int tentativas,
                   string letrasUsadas,
                   string mensagem) {

    cout << mensagem << endl;
    cout << "Palavra: " << mascara << endl;
    cout << "Tentativas restantes: " << tentativas << endl;
    cout << "Letras usadas: ";

    for (char letra : letrasUsadas) {
        cout << letra << " ";
    }
    cout << endl;
}

/* ==============================
   Função principal do jogo
   ============================== */
int jogar(int jogadores) {

    string palavraSecreta;

    // Escolha da palavra
    if (jogadores == 1) {
        palavraSecreta = palavraAleatoria();
    } else {
        cout << "Digite a palavra secreta: ";
        cin >> palavraSecreta;
    }

    string mascara = criarMascara(palavraSecreta.size());
    string letrasUsadas = "";
    int tentativasRestantes = 10;
    string mensagem = "Bem-vindo ao Jogo da Forca!";

    // Loop principal do jogo
    while (mascara != palavraSecreta && tentativasRestantes > 0) {

        limparTela();
        mostrarStatus(mascara, tentativasRestantes, letrasUsadas, mensagem);

        cout << "\nDigite uma letra (ou 1 para arriscar a palavra): ";
        char letra;
        cin >> letra;
        letra = tolower(letra);

        // Arriscar a palavra inteira
        if (letra == '1') {
            string palpite;
            cout << "Digite a palavra: ";
            cin >> palpite;

            if (palpite == palavraSecreta) {
                mascara = palavraSecreta;
            } else {
                tentativasRestantes = 0;
            }
            break;
        }

        // Verifica se a letra já foi usada
        if (letrasUsadas.find(letra) != string::npos) {
            mensagem = "Essa letra já foi digitada!";
            continue;
        }

        letrasUsadas += letra;
        bool acertou = false;

        // Verifica se a letra existe na palavra
        for (int i = 0; i < palavraSecreta.size(); i++) {
            if (palavraSecreta[i] == letra) {
                mascara[i] = letra;
                acertou = true;
            }
        }

        if (acertou) {
            mensagem = "Você acertou!";
        } else {
            mensagem = "Você errou!";
            tentativasRestantes--;
        }
    }

    limparTela();

    // Resultado final
    if (mascara == palavraSecreta) {
        cout << "🎉 Parabéns! Você venceu!\n";
    } else {
        cout << "💀 Você perdeu!\n";
        cout << "A palavra era: " << palavraSecreta << endl;
    }

    cout << "\nDeseja jogar novamente?\n1 - Sim\n2 - Não\n";
    int opcao;
    cin >> opcao;
    return opcao;
}

/* ==============================
   Menu principal
   ============================== */
void menu() {
    int opcao;

    do {
        limparTela();
        cout << "=== JOGO DA FORCA ===\n";
        cout << "1 - Jogar sozinho\n";
        cout << "2 - Jogar em dupla\n";
        cout << "3 - Sobre\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (jogar(1) == 1) continue;
                break;
            case 2:
                if (jogar(2) == 1) continue;
                break;
            case 3:
                limparTela();
                cout << "Jogo da Forca em C++\n";
                cout << "Versão didática para estudo\n";
                cout << "\nPressione ENTER para voltar...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                cout << "Até mais!\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 4);
}

/* ==============================
   Função principal
   ============================== */
int main() {
    srand(time(nullptr));
    menu();
    return 0;
}