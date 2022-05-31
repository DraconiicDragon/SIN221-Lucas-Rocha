#include <iostream>
#include <time.h>
// autor: Lucas Rocha Ferreira

// Constante que define a largura e altura do tabuleiro
// podendo possuir qualquer número inteiro positivo
#define SIZE 3

using namespace std;

// Função que checa todas as posibilidades de vitória
// de acordo com qual jogador fez a última jogada
bool checkBoard(string board[], string player) {
    
    int inARoll;  // Inteiro para verificar quantos espaços marcados em sequência um jogador possui  
    int cont = 0; // Contador utilizado para várias tarefas

    // Verifica todas as possibilidades na horizontal 
    for(int i = 0; i < SIZE; i++) {
        inARoll = 0;
        for(int j = 0; j < SIZE; j++) {
            if(board[cont+j] == player) {
                inARoll++;
            }
        }
        if(inARoll == SIZE) {
            return true;
        }
        cont += SIZE;
    }

    // Verifica todas as possibilidades na vertical   
    for(int i = 0; i < SIZE; i++) {
        inARoll = 0;
        cont = 0;
        for(int j = 0; j < SIZE; j++) {
            if(board[i+cont] == player) {
                inARoll++;
            }
            cont += SIZE;
        }
        if(inARoll == SIZE) {
            return true;
        }
    }

    // Verifica a diagonal
    cont = 0;
    inARoll = 0;
    for(int i = 0; i < SIZE; i++) {
        if(board[cont] == player) {
            inARoll++;
        }
        if(inARoll == SIZE) {
            return true;
        }
        cont += SIZE+1;
    }

    // Verifica a diagonal inversa
    cont = SIZE-1;
    inARoll = 0;
    for(int i = SIZE-1; i >= 0 ; i--) {
        if(board[cont] == player) {
            inARoll++;
        }
        if(inARoll == SIZE) {
            return true;
        }
        cont += SIZE - 1;
    }
    return false;
}

// Função para desenhar as linhas compostas de "---"
void drawLine() {
    cout << "    ";
    for(int j = 0; j < SIZE * 4+1; j++) {
        cout << "-";
    }
}

// Função para desenhar o tabuleiro
void drawBoard(string board[]) {
    int cont = 0;
    cout << "  +   ";
    for(int i = 0; i < SIZE ; i++) {
        cout << i+1 << "   ";
    }
    cout << "\n";
    for(int i = 0; i < SIZE ; i++) {
        drawLine();
        cout << "\n ";
        if(cont < 10) {
            cout << " ";
        }
        cout << cont << " ";
        for(int j = 0; j < SIZE ; j++) {
            cout << "| " << board[cont] << " ";
            cont++;
        }
        cout << "|\n";
    }
    drawLine();
    cout << "\n";
}

int verificar_inteiro() {
    int num; // Recebe o valor a ser lido

    // Enquanto 'num' não for um inteiro o loop repete
    while (scanf("%d", &num) != 1) {

        // Passando um vetor estatico de tamanho 256
        static char temp[256];
        // fgets-Lendo a string
        // sizeof-Fornece o tamanho do vetor temp
        // stdin-Dispositivo de entrada padrão
        fgets(temp, sizeof(temp), stdin);
        cout << "Digite um numero: ";
    }
    return num;
}

// Função onde ocorre todas as partidas
string game(bool ai) {
    string board[SIZE * SIZE]; // Vetor para armazenar as jogadas 
    string player = "X";       // Variável para definir de qual jogador é a vez

    bool turn = true;    // Variável para alternar os turnos
    bool winner = false; // Variável para checar se houve um vencedor na partida
    
    int option;    // Variável para armazenar a posição que o jogador deseja marcar
    int turns = 0; // Variável para contar a quantidade de turnos passados

    srand(time(NULL));

    // FOR para preencher o vetor com espaços vazios
    for(int i = 0; i < SIZE * SIZE; i++) {   
        board[i] = " ";
    }

    // Loop principal do jogo
    while(turns < SIZE * SIZE) {

        // Lê qual a posição que o jogador deseja marcar
        if(!ai || (ai && turn)) {
            drawBoard(board);
            cout << "Vez do jogador " << player << " (1 a "<< SIZE*SIZE << ")\n";
            option = verificar_inteiro();   
            option--;
        } else {
            option = rand() % (SIZE * SIZE);
        }
        

        // Checa se a posição que o jogador deseja marcar está disponivel
        if(board[option] == " ") {

            // Caso sim, a posição escolhida é marcada com o caracter do jogador atual
            board[option] = player;
            
            // Aumenta 1 na quantidade de turnos passados
            turns++;

            // IF para checar se já se passaram o mínimo de turnos necessários para uma vitória
            if(turns > SIZE * 2 - 2) {
                // Caso sim, chama a função "checkBoard()" para checar se há um vencedor
                // Caso a função retorne TRUE, a variável "winner" é atualizada para TRUE
                // e o loop é quebrado     
                if(checkBoard(board, player)) {
                    system("cls");
                    winner = true;
                    break;
                }

            }            

            // Faz a troca da vez do jogador X para o jogador O e vice-versa
            if(turn) {
                player = "O";
                turn = false;
            } else {
                player = "X";
                turn = true;
            }

            system("cls");

        }

        // Caso não, é exibida uma mensagem que informa o jogador do erro ocorrido e o turno não é contado
        else if(!ai || (ai && turn)) {
            system("cls");
            cout << "Jogada Invalida!\n";              
        }   
    }

    drawBoard(board);

    // Caso a variável "winner" for atualizada para TRUE durante o loop principal
    // quer dizer que um dos jogadores ganhou e já que o BREAK ocorre antes da troca dos
    // o último a fazer a jogada é o vencedor
    if(winner) {
        cout << "Vitoria do Jogador " << player;
        return player;
    }

    // Caso não, exibe a mensagem de empate
    else {
        cout << "Empate";
        return "";
    }
}

int main() {

    int xWins = 0, // Variável para contar o número de vitórias do jogador X
    oWins = 0,     // Variável para contar o número de vitórias do jogador O
    draws = 0;     // Variável para contar o número de empates

    string winner; // Variável para receber o ganhador da ultima partida
    int opcao;     // Variável para receber a escolha do usuário no menu
    bool ai;       // Variável para definir se as jogadas do jogador O serão executadas por uma maquina ou uma pessoa
    
    // WHILE que controla o menu principal
    while(true) {

        // Menu principal
        cout << "--------- Menu ---------\n"
             << " 1 Jogador x Jogador\n"
             << " 2 Jogador x Computador\n"
             << " 3 Sair\n"
             << "------------------------\n";
        cin >> opcao;
        system("cls");

        // Define se uma "IA" vai controlar ou não o jogador O
        // TRUE para sim, FALSE para não
        if(opcao == 1) {
            ai = false;
        } else if(opcao == 2) {
            ai = true;
        } else{
            break;
        }

        // WHILE que repete enquanto o usuário digitar "s" no final de cada partida
        while(true) {
            winner = game(ai);

            if(winner == "X") {
                xWins++;
            } else if(winner == "O") {
                oWins++;
            } else {
                draws++;
            }

            cout << "\nJogar Novamente? (s/n)\n";
            cin >> winner;
            if(winner != "s") {
                break;
            }
            system("cls");
        }
        system("cls");

        // Mostra o placar no final do jogo
        cout << "---- Placar ----\n Vitorias X: " << xWins << "\n Vitorias O: "
        << oWins << "\n Empates: " << draws << "\n----------------\n";

        system("pause");
        system("cls");
    }
    return 0;
}
