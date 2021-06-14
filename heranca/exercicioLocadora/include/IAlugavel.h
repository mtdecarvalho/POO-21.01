#ifndef _IALUGAVEL_H_
#define _IALUGAVEL_H_

#include <iostream>
using namespace std;

class IAlugavel
{
    public:
        virtual void ler() = 0;
        virtual double alugel() = 0;
        virtual void mostrar() = 0;
        virtual int getCodigo() = 0;           
        virtual int getAnoDeLancamento() = 0;  
        virtual string getTipo() = 0;          
        virtual string getTitulo() = 0;        
        virtual string getEstilo() = 0;        
        virtual string getProdutora() = 0;     
        virtual string getMidia() = 0;   
};

#endif