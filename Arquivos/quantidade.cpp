#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream arqEntrada("teste.txt");
    int i = 0;
    char aux2[100];
    while(!arqEntrada.eof()) {
        arqEntrada.getline(aux2,100);
        i++;
    }
    cout << i;
    
    

    return 0;
}