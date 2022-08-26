#include <iostream>
#include <string.h>

using namespace std;

typedef struct Pessoa {
    char nome[30];
    char endereco[50];
    char telefone[15];
};

int main() {
    Pessoa pessoas[5];
    for(int i = 0; i < 5; i++) {
        cin.getline(pessoas[i].nome,30);
        // cin.getline(pessoas[i].endereco,50);
        // cin.getline(pessoas[i].telefone,15);
    }

    char nome[30];
    int posicoes[5];
    strcpy(nome,pessoas[0].nome);
    posicoes[0] = 0;
   
    for(int i = 0; i < 5; i++) {
        for(int j = 1; j < 5; j++) {
            if(strcmp(pessoas[j].nome,nome) > 0) {
                strcpy(nome,pessoas[j].nome);
                posicoes[0] = j;
            }
        }
        cout << nome << endl;
    }

    return 0;
}