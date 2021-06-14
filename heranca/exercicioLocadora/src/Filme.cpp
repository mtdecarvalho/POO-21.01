#include "Filme.h"

string Filme::getTipo()                    { return "Filme";        }
string Filme::getAtorPrincipal()           { return atorPrincipal;  }
string Filme::getDiretor()                 { return diretor;        }

void Filme::ler()
{
    Item::ler();
    cout << "Insira o nome do ator principal: "; getline(cin, atorPrincipal);
    cout << "Insira o nome do diretor: "; getline(cin, diretor);
}

double Filme::alugel()
{
    return getAnoDeLancamento() < 2020 ? 5.00 : 7.00;
}