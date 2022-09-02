#include <iostream>

using namespace std;

typedef struct Item{
    int id;
    string nome;
    string telefone;
    string celular;
    string email;
    int idade;
};

typedef struct Elemento* Apontador;

typedef struct Elemento{
    Item item;
    struct Elemento *prox;
};

typedef struct Lista{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
};

void CriaListaVazia(Lista *lista)
{
    lista->primeiro = new Elemento;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
    cout << "Lista criada com sucesso!";
    cout << "Lista já existe!";
}

bool VerificaListaVazia(Lista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(Lista *lista)
{
    return lista->tamanho;
}

void InsereListaPrimeiro(Lista *lista, Item *item)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new Elemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    lista->tamanho++;
    AtualizaUltimo(lista);
}

void AtualizaUltimo(Lista *lista)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(Lista *lista, Item *item)
{
    lista->ultimo->prox = new Elemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

void InsereListaAposElemento(Lista *lista, Item *item, int id)
{
    Apontador aux, pAux, x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL)
    {
        if (pAux->item.id == id)
        {
            find = true;
            x = pAux;
            aux = x->prox;
            x->prox = new Elemento;
            x->prox->prox = aux;
            x->prox->item = *item;
            break;
        }
        pAux = pAux->prox; /* próxima célula */
    }
    if (find)
    {
        cout << "Item inserido com sucesso!";
        AtualizaUltimo(lista);
        lista->tamanho++;
    }
    else
    {
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void ImprimeLista(Lista lista)
{
    if (VerificaListaVazia(&lista))
    {
        cout << "Lista vazia!\n";
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl
             << endl;
        aux = aux->prox;
    }
    system("pause");
}

int PesquisaItem(Lista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return aux->item.id;
        }
        aux = aux->prox;
    }
    return -1;
}

void ImprimeItem(Lista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "ID: " << aux->item.id << endl;
            cout << "Nome: " << aux->item.nome << endl
                 << endl;
            break;
        }
        aux = aux->prox;
    }
}

void RemoveListaPrimeiro(Lista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(Lista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo)
    {
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(Lista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }

    Apontador aux, anterior, x;

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}