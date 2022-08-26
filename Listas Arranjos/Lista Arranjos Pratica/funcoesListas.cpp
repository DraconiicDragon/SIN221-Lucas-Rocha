#define MAX_TAM 30
#include <iostream>

using namespace std;

struct TipoItem {
    string nome;
    string matricula;
    string turma;
    float p1, p2, p3;
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
int localizaItem(TipoLista *lista, string id) {
    for(int i = 0; i < lista->tamanho; i++) {
        if(lista->item[i].matricula == id) {
            return i;
        } 
    }
    return -1;
}

// Adaptar "int chave" para cada projeto 
void removeItem(TipoLista *lista, string id) {
    int posicao = localizaItem(lista, id);
    for(int i = posicao; i < lista->tamanho; i++) {
        lista->item[i] = lista->item[i+1];
    }
    lista->tamanho--;
}

// Adaptar "cout << chave" para cada projeto 
void imprimeLista(TipoLista lista, string turma) {
    for(int i = 0; i < lista.tamanho; i++) {
        if(lista.item[i].turma == turma) {
            cout << "Matricula: " << lista.item[i].matricula << " - Nome: " << lista.item[i].nome 
            << " - Turma: " << lista.item[i].turma << " - Media: " << (lista.item[i].p1+lista.item[i].p2+lista.item[i].p3)/3 << endl;
        }
    }
}