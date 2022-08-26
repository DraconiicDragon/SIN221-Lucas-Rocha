#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream arqSaida("matriz.xls");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            arqSaida << 1 << "\t";
        }
        cout << endl;
    }
    return 0;
}