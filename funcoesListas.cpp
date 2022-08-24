#define MAX_TAM 30
#include <iostream>

struct TipoItem {
    int chave;
};

struct TipoLista {
    TipoItem item[MAX_TAM];
    int tamanho;
};

void criaListaVazia(TipoLista &lista) {
    lista.tamanho = 0;
}

bool verificaListaVazia(TipoLista &lista) {
    if(lista.tamanho == 0) {
        return true;
    } else {
        return false;
    }
}

bool verificaListaCheia(TipoLista &lista) {
    if(lista.tamanho == MAX_TAM) {
        return true;
    } else {
        return false;
    }
}

bool insereItem(TipoLista &lista, TipoItem item) {
    if(!verificaListaCheia(lista)) {
        lista.item[lista.tamanho] = item;
        lista.tamanho++;
        return true;
    } else {
        return false;
    }
}

int localizarItem(TipoLista &lista, TipoItem item) {
    for(int i = 0; i < lista.tamanho; i++) {
        if(lista.item[i] == item){
            return i;
        }
    }
}

void removeItem(TipoLista &lista, TipoItem item) {
    int posicao = localizarItem(lista, item);
    delete &lista.item[posicao];
    for(int i = posicao; i < lista.tamanho-1; i++) {
        lista.item[i] = lista.item[i+1];
    }
    delete &lista.item[MAX_TAM-1];
    lista.tamanho--;
}

void imprimeLista(TipoLista &lista) {
    for(int i = 0; i < lista.tamanho; i++) {
        std::cout << lista.item[i].chave << std::endl;
    }
}