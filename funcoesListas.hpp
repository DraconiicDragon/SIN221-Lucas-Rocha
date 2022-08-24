#include "funcoesListas.cpp"

struct TipoItem;
struct TipoLista;
void criaListaVazia(TipoLista &lista);
bool verificaListaVazia(TipoLista &lista);
bool verificaListaCheia(TipoLista &lista);
bool insereItem(TipoLista &lista, TipoItem item);
int localizarItem(TipoLista &lista, TipoItem item);
void removeItem(TipoLista &lista, int posicao);
void imprimeLista(TipoLista &lista);