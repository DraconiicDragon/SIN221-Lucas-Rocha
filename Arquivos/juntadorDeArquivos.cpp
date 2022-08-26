#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream arqEntrada1("teste.txt");
    ifstream arqEntrada2("teste2.txt");
    ofstream arqSaida("resultado.txt");
    char aux[100];

    while(!arqEntrada1.eof()) {
        arqEntrada1.getline(aux,100);
        arqSaida << aux << endl;
    }
    while(!arqEntrada2.eof()) {
        arqEntrada2.getline(aux,100);
        arqSaida << aux << endl;
    }

    return 0;
}