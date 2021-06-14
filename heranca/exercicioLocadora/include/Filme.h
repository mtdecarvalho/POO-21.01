#ifndef _FILME_H_
#define _FILME_H_

#include "Item.h"

class Filme : public Item
{
    protected:
        string atorPrincipal, diretor;
    public:
        void ler();
        double alugel();
        string getTipo();//                    { return "Filme"; }
        string getAtorPrincipal();//           { return atorPrincipal; }
        string getDiretor();//                 { return diretor;       }
};

#endif