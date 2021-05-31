#include <iostream>

using namespace std;

int menu()
{
    int opcao;
    cout << "Bem vindo ao Sistema Academico" << endl
    << "1. Inserir disciplina" << endl
    << "2. Remover disciplina" << endl
    << "3. Alterar disciplina" << endl
    << "4. Listar todas as disciplinas" << endl 
    << "5. Listar todas as disciplinas de tipo 2" << endl
    << "6. Listar todas as disciplinas de tipo 3 com nota de apresentacao maior que 7" << endl
    << "0. Sair" << endl
    << "Entre com sua opcao: ";
    cin >> opcao;
    return opcao;
}