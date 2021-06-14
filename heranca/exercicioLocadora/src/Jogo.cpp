#include "Jogo.h"

int Jogo::getNumeroDeJogadores()      { return numeroDeJogadores;   }
string Jogo::getTipo()                { return "Jogo";              }
string Jogo::getPlataforma()          { return plataforma;          }

void Jogo::ler()
{
    Item::ler();
    cout << "Insira o numero de jogadores: "; cin >> numeroDeJogadores;
    cout << "Insira a plataforma: "; cin.ignore(); getline(cin, plataforma);
}

double Jogo::alugel()
{
    double desconto;
    if ( plataforma == "xbox series" || plataforma == "ps5" || plataforma == "nintendo switch" )
        desconto = 1.0;
    else
        desconto = 0.6;

    return getAnoDeLancamento()<2020 ? desconto * 7.00 : desconto * 12.00;
}