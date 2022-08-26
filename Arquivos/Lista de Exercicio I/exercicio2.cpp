#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nome, telefone;
    ofstream arqSaida("excel.xls");
    for(int i = 0; i < 2; i++) {
        cin >> nome;
        cin >> telefone;
        arqSaida << nome << "\t";
        arqSaida << telefone << endl;
    }
    
    return 0;
}