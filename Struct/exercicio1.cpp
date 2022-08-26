#include <iostream>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Dados_Pessoais {
    char nome[50];
    int idade;
    char sexo;
    char cpf[12];
    Data data;
};

struct Dados_Funcionais {
    int id_setor;
    char cargo[50];
    float salario;
};

int main() {
    Dados_Pessoais dp;
    Dados_Funcionais df;

    cin.getline(dp.nome,50);
    cin >> dp.idade;
    cin >> dp.sexo;
    cin.ignore();
    cin.getline(dp.cpf, 12);
    cin >> dp.data.dia;
    cin >> dp.data.mes;
    cin >> dp.data.ano;
    cin >> df.id_setor;
    cin.ignore();
    cin.getline(df.cargo,50);
    cin >> df.salario;

    cout << endl;
    cout << dp.nome << endl;
    cout << dp.idade << endl;
    cout << dp.sexo << endl;
    cout << dp.cpf << endl;
    cout << dp.data.dia << endl;
    cout << dp.data.mes << endl;
    cout << dp.data.ano << endl;
    cout << df.id_setor << endl;
    cout << df.cargo << endl;
    cout << df.salario << endl;
    
    

    return 0;
}