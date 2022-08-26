#include <iostream>
#include <fstream>
#include <time.h>   

using namespace std;

int main() {
    ofstream arqSaida("teste.txt");
    srand(time(NULL));

    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 100; j++) {
            char aux;
            aux = rand() % 25 + 97;
            arqSaida << aux;
        }
        arqSaida << endl;
    }

    ifstream arqEntrada("teste.txt");

    char linha[100];
    while(!arqEntrada.eof()) {
        
    }
    

    return 0;
}