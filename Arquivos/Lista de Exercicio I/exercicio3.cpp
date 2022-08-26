#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int decimal, binary, remainder, product;
    ofstream arqSaida("teste.txt");
    for(int i = 0; i < 2; i++) {
        cin >> decimal;
        binary = 0;
        product = 1;
        while (decimal != 0) {
            remainder = decimal % 2;
            binary = binary + (remainder * product);
            decimal = decimal / 2;
            product *= 10;
        }
        arqSaida << binary << endl;
    }
    

    

    return 0;
}