#include <iostream>
#include <string.h>

using namespace std;

struct Livro {
    char titulo[30];
    char categoria[15];
    char autor[20];
    char editora[15];
    int paginas;
    int ano;
};

int main() {
    Livro livros[5];

    for(int i = 0; i < 5; i++) {
        cin.getline(livros[i].titulo,30);
        cin.getline(livros[i].categoria,15);
        cin.getline(livros[i].autor,20);
        cin.getline(livros[i].editora,15);
        cin >> livros[i].paginas;
        cin >> livros[i].ano;
        cin.ignore();
    }
    cout << livros[0].titulo << endl; 

    char titulo[30];
    cout << "Qual livro deseja buscar?:" << endl;
    cin.getline(titulo,30);

    for(Livro i : livros) {
        if(strcmp(titulo, i.titulo) == 0) {
            cout << i.titulo << endl << i.categoria << endl << i.autor << endl << i.editora << endl << i.paginas << endl << i.ano << endl;
        }
    }
    

    return 0;
}