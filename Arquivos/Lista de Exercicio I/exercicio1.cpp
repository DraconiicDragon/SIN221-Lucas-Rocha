#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nome;
    cin >> nome;

    ifstream arqEntrada(nome);
    if(arqEntrada) {
        cout << "positivo";
    } else {
        cout << "negativo";
    }

    return 0;
}