#include <iostream>
#include "funcoesListas.hpp"

using namespace std;

int main() {
    TipoItem aluno;
    TipoLista lista;

    criaListaVazia(&lista);

    aluno.matricula = "1";
    aluno.nome = "BenDover";
    aluno.turma = "doPagode";
    aluno.p1 = 3;
    aluno.p2 = 5;
    aluno.p3 = 10;
    
    insereItem(&lista, aluno);

    aluno.matricula = "2";
    aluno.nome = "BarryMikeHawkInner";
    aluno.turma = "2";
    aluno.p1 = 6;
    aluno.p2 = 10;
    aluno.p3 = 10;

    insereItem(&lista, aluno);

    aluno.matricula = "3";
    aluno.nome = "SussusAmougus";
    aluno.turma = "doPagode";
    aluno.p1 = 4;
    aluno.p2 = 12;
    aluno.p3 = 8;

    insereItem(&lista, aluno);

    imprimeLista(lista, "doPagode");

    removeItem(&lista, "1");
    cout << endl;
    imprimeLista(lista, "doPagode");
    return 0;
}