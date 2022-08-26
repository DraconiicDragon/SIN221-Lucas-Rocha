#include <iostream>

using namespace std;

struct Veiculo {
    string marca;
    int ano;
    float preco;
};

int main() {
    Veiculo veiculos[5];
    veiculos[0] = {"XBOXSERIESX", 1945, 8000.0};
    veiculos[1] = {"LOGITEC", 2001, 6000.0};
    veiculos[2] = {"LILNUSNUS", 1999, 15000.0};
    veiculos[3] = {"FORTNITEBATTLEBUS", 2015, 69000.0};
    veiculos[4] = {"MUSTANG", 2077, 2.5};

    int valor;
    cin >> valor;

    for(Veiculo i : veiculos) {
        if(i.preco <= valor) {
            cout << i.marca << endl;
            cout << i.ano << endl;
            cout << i.preco << endl;
            cout << endl;
        }
    }
   
    return 0;
}