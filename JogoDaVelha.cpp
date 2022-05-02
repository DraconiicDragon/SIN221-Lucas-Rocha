#include <iostream>

using namespace std;

// Constante que define a largura e altura do tabuleiro
// podendo possuir qualquer número inteiro positivo
const int SIZE = 1;

// Função que checa todas as posibilidades de vitória
// de acordo com qual jogador fez a última jogada
bool checkBoard(string board[], string player) {
    
    int inARoll;  // Inteiro para verificar quantos espaços em sequência um jogador possui  
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
        cont += SIZE-1;
    }
    return false;
}

// Função para desenhar as linhas compostas de "---"
void drawLine() {
    cout << "    ";
    for(int j = 0; j < SIZE*4+1; j++) {
        cout << "-";
    }
}

// Função para desenhar o tabuleiro
void drawBoard(string board[]) {
    int cont = 0;
    cout << "  +   ";
    for(int i = 0; i < SIZE; i++) {
        cout << i+1 << "   ";
    }
    cout << "\n";
    for(int i = 0; i < SIZE; i++) {
        drawLine();
        cout << "\n ";
        if(cont < 10) {
            cout << " ";
        }
        cout << cont << " ";
        for(int j = 0; j < SIZE; j++) {
            cout << "| " << board[cont] << " ";
            cont++;
        }
        cout << "|\n";
    }
    drawLine();
    cout << "\n";
}

// Função onde ocorre todas as partidas
string game() {
    string board[SIZE*SIZE]; // Vetor para armazenar as jogadas 
    string player = "X";     // Variável para definir de qual jogador é a vez

    bool turn = true;    // Variável para alternar os turnos
    bool winner = false; // Variável para checar se houve um vencedor na partida
    
    int option;    // Variável para armazenar a posição que o jogador deseja marcar
    int turns = 0; // Variável para contar a quantidade de turnos passados

    // FOR para preencher o vetor com espaços vazios
    for(int i = 0; i < SIZE*SIZE; i++) {   
        board[i] = " ";
    }

    // Loop principal do jogo
    while(turns < SIZE*SIZE) {

        drawBoard(board);

        // Lê qual a posição que o jogador deseja marcar
        cout << "Vez do jogador " << player << " (1 a "<< SIZE*SIZE << ")\n";
        cin >> option;       
        option--;

        // Checa se a posição que o jogador deseja marcar está disponivel
        if(board[option] == " ") {

            // Caso sim, a posição escolhida é marcada com o caracter do jogador atual
            board[option] = player;
            
            // Aumenta 1 na quantidade de turnos passados
            turns++;

            // IF para checar se já se passaram o mínimo de turnos necessários para uma vitória
            if(turns > SIZE * 2 - 2) {

                // Caso sim, chama a função "checkBoard()" para checar se há um vencedor
                // Caso a função retorne TRUE, a variável "winner" é atualizada para TRUE e o loop é quebrado     
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
        else {
            system("cls");
            cout << "Jogada Invalida!\n";
        }   
    }

    drawBoard(board);

    // Caso a variável "winner" for atualizada para TRUE durante o loop principal
    // quer dizer que um dos jogadores ganhou e já que o BREAK ocorre antes da troca dos jogadores ser realizada
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

    // Variáveis para contar o placar de vitórias e empates
    int xWins = 0, oWins = 0, draws = 0;

    // Variável para receber o ganhador da ultima partida
    string winner;

    // WHILE que repete enquanto o usuário digitar "s" no final de cada partida
    while(true) {

        winner = game();

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

    // Mostra o placar no final do programa
    cout << "Placar\n-------------\nVitorias X: " << xWins << "\nVitorias O: "
    << oWins << "\nEmpates: " << draws << "\n-------------\n";

    system("pause");

    return 0;
}
