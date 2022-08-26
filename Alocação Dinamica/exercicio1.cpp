#include <iostream>

using namespace std;

void preencher(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
}

int main() {
    int tamanho;
    cin >> tamanho;
    int * vetor = new int[tamanho];
    preencher(vetor, tamanho);

    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }

    delete [] vetor;
    return 0;
}