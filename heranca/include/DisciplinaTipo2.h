#ifndef _DISCIPLINA_TIPO2_H_
#define _DISCIPLINA_TIPO2_H_

#include "Disciplina.h"
#include "DisciplinaTipo1.h"
#include <string.h>

using namespace std;

class Tipo2 : public Tipo1
{
    public:
        string getTipo();
        double media();
};

#endif