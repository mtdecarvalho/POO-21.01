#ifndef _LOCADORA_H_
#define _LOCADORA_H_

#include "IAlugavel.h"
#include "Filme.h"
#include "Jogo.h"

class Locadora
{
    private:
        IAlugavel* v[100];
        int qtd;
    public:
        Locadora();
        ~Locadora();
        void inserir();
        void remover();
        void alterar();
        void listarDadaInformacao();
        void listarJogosPlataforma();
        void listarAlugel();
        int obterIndice();
};

Item* criarItem();

#endif