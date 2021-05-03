#include <iostream>
#include <iomanip>
#include <string>

#include "classes.h"

using namespace std;

void menu ( Historico &a )
{
    int opcao;
    bool fim = 0;
    while (!fim)
    {
        limpartela();
        cout << "\tBem vindo ao sistema academico da FAETERJ! O que deseja fazer?\n" << endl;
        cout << "1. Adicionar uma disciplina no sistema.\n2. Conferir media de uma disciplina.\n3. Mostrar dados de uma disciplina.\n"
                "4. Remover uma disciplina.\n5. Alterar os dados de uma disciplina.\n6. Listar todas as disciplinas disponiveis no sistema.\n0. Encerrar programa." << endl;
                
        cin >> opcao;
        switch ( opcao )
        {
            case 1:
                limpartela(); a.lerGrade();
                break;
            case 2:
                limpartela(); a.mostrarMedia();
                break;
            case 3:
                limpartela(); a.mostrarDisciplina(); pausartela();
                break;
            case 4:
                limpartela(); a.remover();
                break;
            case 5:
                a.alterar();
                break;
            case 6:
                limpartela(); a.mostrarGrade();
                break;
            case 0:
                fim = 1;
                break;
            default:
                break;
        }
    }
} 

int main ()
{
    Historico a;
    bool fim = 0;
    a.inicializar();
    menu(a);
    return 0;
}