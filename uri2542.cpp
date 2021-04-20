#include <iostream>

using namespace std;

class Carta 
{
    private:
        int qtdAtributos, atributos[100];
    public:
        void lerAributos(int qtd);
        int obterValor(int posicao)         { return atributos[posicao]; }
};

class Baralho
{
    private:
        Carta v[100];
        int qtdCartas;
    public:
        void lerCartas(int qtdCartas, int qtdAtributos);
        int obterCarta(int carta, int posicao)      { return v[carta-1].obterValor(posicao-1); }
};

void Carta::lerAributos(int qtd)
{
    qtdAtributos = qtd;
    for ( int i = 0 ; i < qtdAtributos ; i++ )
        cin >> atributos[i];
}

void Baralho::lerCartas(int qtdCartas, int qtdAtributos)
{  
    for ( int i = 0 ; i < qtdCartas ; i ++ )
        v[i].lerAributos(qtdAtributos);
}

int main ()
{
    int N, M, L, cartaM, cartaL, atributo;
    Baralho Marcos, Leonardo;
    while ( cin >> N )
    {
        cin >> M >> L;
        Marcos.lerCartas(M, N);
        Leonardo.lerCartas(L, N);
        cin >> cartaM >> cartaL >> atributo;
        if ( Marcos.obterCarta(cartaM, atributo) > Leonardo.obterCarta(cartaL, atributo) )
            cout << "Marcos" << endl;
        else if ( Marcos.obterCarta(cartaM, atributo) < Leonardo.obterCarta(cartaL, atributo) )
            cout <<"Leonardo" << endl;
        else 
            cout << "Empate" << endl;
    }
    return 0;
}