#include "Disciplina.h"
#include "DisciplinaTipo1.h"
#include "DisciplinaTipo2.h"
#include "DisciplinaTipo3.h"
#include "Historico.h"
#include "menu.h"

#include <iostream>

using namespace std;

// Disciplina* criarDisciplina()
// {
//     int tipo;
//     do
//     {
//         cout << "Selecione o tipo de disciplina:" << endl <<
//                 "1 - Tipo 1" << endl <<
//                 "2 - Tipo 2" << endl <<
//                 "3 - Tipo 3" << endl <<
//                 "Entre com a escolha: ";
//         cin >> tipo;
//     } while ( tipo < 1 || tipo > 3);
//     switch (tipo)
//     {
//         case 1: return new Tipo1();
//         case 2: return new Tipo2();
//         case 3: return new Tipo3();
//         default:
//             cout << "deu ruim"; exit(0);
//     }
// }

int main()
{
    Historico a;
    int opcao;
    do {
        opcao = menu();
        switch ( opcao )
        {
            case 1: a.inserir(); break;
            case 2: a.remover(); break;
            case 3: a.alterar(); break;
            case 4: a.listarDisciplinas(); break;
            case 5: a.listarDisciplinasTipo2(); break;
            case 6: a.listarDisciplinasTipo3(); break;
            default: break;
        }
    } while ( opcao > 0 );
    return 0;
}