#include "Item.h"

int Item::getCodigo()                   { return codigo;            }
int Item::getAnoDeLancamento()          { return anoDeLancamento;   }
string Item::getTitulo()                { return titulo;            }
string Item::getEstilo()                { return estilo;            }
string Item::getProdutora()             { return produtora;         }
string Item::getMidia()                 { return midia;             }

void Item::ler()
{
    cout << "Insira o codigo: "; cin >> codigo;
    cout << "Insira o ano de lancamento: "; cin >> anoDeLancamento;
    cout << "Insira o titulo: "; cin.ignore(); getline(cin, titulo);
    cout << "Insira o estilo: "; getline(cin, estilo);
    cout << "Insira a produtora: "; getline(cin, produtora);
    cout << "Insira o tipo de midia: "; getline(cin, midia);
}

void Item::mostrar()
{
    cout << "Codigo -> " << getCodigo() << " Nome -> " << getTitulo() << endl;
    cout << "Tipo -> " << getTipo() << " Midia -> " << getMidia() << endl;
    cout << "Ano -> " << getAnoDeLancamento() << " Alugel -> " << alugel() << endl;
}