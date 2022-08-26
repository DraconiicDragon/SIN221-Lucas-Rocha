#define MAX_TAM 30
#include <iostream>

struct TipoItem {
    int id;
};

struct TipoLista {
    TipoItem item[MAX_TAM];
    int tamanho;
};

void criaListaVazia(TipoLista *lista) {
    lista->tamanho = 0;
}

bool verificaListaVazia(TipoLista *lista) {
    if(lista->tamanho == 0) {
        return true;
    } else {
        return false;
    }
}

bool verificaListaCheia(TipoLista *lista) {
    if(lista->tamanho == MAX_TAM) {
        return true;
    } else {
        return false;
    }
}

bool insereItem(TipoLista *lista, TipoItem item) {
    if(!verificaListaCheia(lista)) {
        lista->item[lista->tamanho] = item;
        lista->tamanho++;
        return true;
    } else {
        return false;
    }
}

// Adaptar "int chave" para cada projeto 
int localizaItem(TipoLista *lista, int id) {
    for(int i = 0; i < lista->tamanho; i++) {
        if(lista->item[i].id == id) {
            return i;
        } 
    }
    return -1;
}

// Adaptar "int chave" para cada projeto 
void removeItem(TipoLista *lista, int id) {
    int posicao = localizaItem(lista, id);
    for(int i = posicao; i < lista->tamanho; i++) {
        lista->item[i] = lista->item[i+1];
    }
    lista->tamanho--;
}

// Adaptar "cout << chave" para cada projeto 
void imprimeLista(TipoLista lista) {
    for(int i = 0; i < lista.tamanho; i++) {
        std::cout << lista.item[i].id << std::endl;
    }
}