#ifndef _ITEM_H_
#define _ITEM_H_

#include "IAlugavel.h"

class Item : public IAlugavel
{
    private:
        int codigo, anoDeLancamento;
        string titulo, estilo, produtora, midia;
        double aluguel;
    public:
        virtual void ler();
        virtual void mostrar();
        virtual double alugel() = 0;
        int getCodigo();
        int getAnoDeLancamento();
        string getTitulo();
        string getEstilo();
        string getProdutora();
        string getMidia();
};

#endif