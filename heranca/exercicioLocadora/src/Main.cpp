#include "IAlugavel.h"
#include "Item.h"
#include "Filme.h"
#include "Jogo.h"
#include "Locadora.h"
#include "Menu.h"

#include <iostream>

using namespace std;

int main ()
{
    Locadora a;
    int op;
    do
    {
        op = menu();
        switch (op)
        {
            case 1: a.inserir(); break;
            case 2: a.remover(); break;
            case 3: a.alterar(); break;
            case 4: a.listarDadaInformacao(); break;
            case 5: a.listarJogosPlataforma(); break;
            case 6: a.listarAlugel(); break;
            case 0: break;
            default: break;
        }
    } while ( op > 0 );
    return 0;
}