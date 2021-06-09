#ifndef _DISCIPLINA_TIPO1_H_
#define _DISCIPLINA_TIPO1_H_

#include "Disciplina.h"

class Tipo1 : public Disciplina 
{
    protected:
        double nota1, nota2;
    public:
        void ler();
        string getTipo();
        double media();
};

#endif