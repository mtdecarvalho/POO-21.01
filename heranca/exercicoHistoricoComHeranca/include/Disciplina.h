#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_

#include <iostream>

using namespace std;

class Disciplina
{
    private:
        string nome;
        int codigo, creditos, semestre, ano;
    public:
        virtual void ler();
        virtual double media() = 0;     // virtual puro -> metodo abstrato, logo a classe é abstrata
        virtual string getTipo();
        int getCodigo();
        string getNome();
        int getCreditos();
};

#endif