#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream arqEntrada("excelEntrada.csv");
    ofstream arqSaida("excelSaida.csv");
    string nome;
    string sexo;
    string idade;
    // while(!arqEntrada.eof()) {
        
    // }
    nome >> arqEntrada;
    cout << nome;
    
    return 0;
}