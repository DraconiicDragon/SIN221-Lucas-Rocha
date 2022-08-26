#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    ifstream arqEntadada("teste.txt");
    char aux[100];
    int vogais = 0, consoantes = 0;
    while(!arqEntadada.eof()) {
        arqEntadada.getline(aux,100);
        for(int i = 0; i < strlen(aux); i++) {
            if(isalpha(aux[i])) {
                if(aux[i] == 'a' || aux[i] == 'e' || aux[i] == 'i' || aux[i] == 'o' || aux[i] == 'u') {
                    vogais++;
                } else {
                    consoantes++;
                }
            }   
        }
    }
    cout << vogais << " " << consoantes;
    return 0;
}   