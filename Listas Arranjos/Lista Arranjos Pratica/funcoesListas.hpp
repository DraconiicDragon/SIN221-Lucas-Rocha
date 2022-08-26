#ifndef FUNCOESLISTAS_H
#define FUNCOESLISTAS_H


#include "funcoesListas.cpp"

struct TipoItem;
struct TipoLista;
void criaListaVazia(TipoLista *lista);            // Inicializa a variavel "tamanho" como 0
bool verificaListaVazia(TipoLista *lista);        // Verifica se a lista está vazia (tamanho == 0)
bool verificaListaCheia(TipoLista *lista);        // Verifica se a lista está cheia (tamanho == MAX_TAM)
bool insereItem(TipoLista *lista, TipoItem item); // Insere um novo item na lista
int localizaItem(TipoLista *lista, string id);       // Procura um item usando o id e retorna sua posição
void removeItem(TipoLista *lista, string id);        // Remove um item usando o id
void imprimeLista(TipoLista lista, string turma);               // Imprime o id de todos os itens

#endif