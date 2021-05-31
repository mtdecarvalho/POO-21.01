#ifndef _HISTORICO_H_
#define _HISTORICO_H_

#include "Disciplina.h"

class Historico
{
    private:
        Disciplina* v[100];
        int qtd;
    public:
        Historico();
        virtual ~Historico();
        int obterIndice();
        void inserir();
        void remover();
        void alterar();
        void listarDisciplinas();
        void listarDisciplinasTipo2();
        void listarDisciplinasTipo3();
};

Disciplina* criarDisciplina();

#endif