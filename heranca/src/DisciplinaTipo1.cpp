#include "DisciplinaTipo1.h"

#include <iostream>

string Tipo1::getTipo()           { return "Tipo1";           }
double Tipo1::media()             { return (nota1+nota2)/2;   }

void Tipo1::ler()
{
    Disciplina::ler();
    cout << "Nota 1 -> "; cin >> nota1;
    cout << "Nota 2 -> "; cin >> nota2;
}