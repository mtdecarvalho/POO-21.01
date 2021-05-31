#include "DisciplinaTipo3.h"

using namespace std;

string Tipo3::getTipo()                     { return "Tipo3";                                                   }
double Tipo3::getNotaApresentacao()         { return notaApresentacao;                                          }
double Tipo3::media()                       { return (2*notaMonografia  + 3*notaApresentacao + notaPratica)/6; }

void Tipo3::ler()
{
    Disciplina::ler();
    cout << "Nota da Monografia -> "; cin >> notaMonografia;
    cout << "Nota da Apresentacao -> "; cin >> notaApresentacao;
    cout << "Nota Pratica -> "; cin >> notaPratica;
}