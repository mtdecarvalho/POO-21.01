#ifndef _DISCIPLINA_TIPO3_H_
#define _DISCIPLINA_TIPO3_H_

#include "Disciplina.h"

class Tipo3 : public Disciplina
{
    private:
        double notaMonografia, notaApresentacao, notaPratica;
    public:
        void ler();
        string getTipo();
        double getNotaApresentacao();
        double media();
};

#endif