#include "Disciplina.h"

#include <iostream>

string Disciplina::getTipo()                { return "Tipo";        }
int Disciplina::getCodigo()                 { return codigo;        }
string Disciplina::getNome()                { return nome;          }   
int Disciplina::getCreditos()               { return creditos;      }

void Disciplina::ler()
{
    cout << "Codigo -> "; cin >> codigo;
    cout << "Nome -> "; cin.ignore(); getline(cin, nome);
    cout << "Creditos -> "; cin >> creditos;
    cout << "Semestre -> "; cin >> semestre;
    cout << "Ano -> "; cin >> ano;
}