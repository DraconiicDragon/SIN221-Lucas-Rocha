#ifndef LISTA_H
#define LISTA_H

typedef struct Item;

typedef struct Elemento *Apontador;

typedef struct Elemento;
typedef struct Lista;

bool listaCriada = false;

void CriaListaVazia(Lista *lista);
bool VerificaListaVazia(Lista *lista);
void InsereListaPrimeiro(Lista *lista, Item *item);
void InsereListaAposElemento(Lista *lista, Item *item, int id);
void InsereListaUltimo(Lista *lista, Item *item);
void AtualizaUltimo(Lista *lista);
void ImprimeLista(Lista lista);
int PesquisaItem(Lista *lista, int chave);
void ImprimeItem(Lista *lista, int id);
void RemoveListaPrimeiro(Lista *lista);
void RemoveListaUltimo(Lista *lista);
void RemoveItemPorId(Lista *lista, int id);
int TamanhoLista(Lista *lista);

#endif