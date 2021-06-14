#include "Menu.h"

#include <iostream>

using namespace std;

int menu()
{
    int op;
    cout << "Bem vindo a locadora!" << endl;
    cout << "1 - Inserir um novo item" << endl;
    cout << "2 - Remover um item dado o codigo" << endl;
    cout << "3 - Alterar dados de um item" << endl;
    cout << "4 - Listar itens dado um filtro" << endl;
    cout << "5 - Listar os jogos de uma plataforma" << endl;
    cout << "6 - Mostrar o valor do alugel dado o codigo" << endl;
    cout << "0 - Sair" << endl;
    cout << "Entre com a opcao: "; cin >> op;
    return op;
}