#include <iostream>
#include "funcoesListas.hpp"

using namespace std;

int main() {
    TipoLista lista;
    criaListaVazia(lista);

    TipoItem item1;
    TipoItem item2;
    TipoItem item3;

    item1.chave = 9;
    item2.chave = 15;
    item3.chave = 17;

    insereItem(lista,item1);
    insereItem(lista,item2);
    insereItem(lista,item3);

    imprimeLista(lista);
    cout << endl;
    cout << localizarItem(lista,item1) << endl;
    removeItem(lista,item2);

    cout << endl;
    imprimeLista(lista);



    return 0;
}