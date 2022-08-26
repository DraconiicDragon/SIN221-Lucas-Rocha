#include <iostream>
#include "calculadora.hpp"

using namespace std;

int main() {
    float valor1 = -30, valor2 = -20;

    valor1 = modulo(valor1);
    valor2 = modulo(valor2);
    cout << soma(valor1, valor2) << endl;
    cout << subtracao(valor1, valor2) << endl;
    cout << divisao(valor1, valor2) << endl;
    cout << multiplicacao(valor1, valor2) << endl;
    return 0;
}