#ifndef _JOGO_H_
#define _JOGO_H_

#include "Item.h"

class Jogo : public Item
{
    protected:
        int numeroDeJogadores;
        string plataforma;
    public:
        void ler();
        double alugel();
        string getTipo();//                { return "Jogo"; }
        int getNumeroDeJogadores();//      { return numeroDeJogadores; }
        string getPlataforma();//          { return plataforma; }
};

#endif