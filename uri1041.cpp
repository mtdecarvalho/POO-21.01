#include <iostream>

using namespace std;

class Ponto
{
    private:
        double x, y;
    public:
        void ler();
        string obterQuadrante();
        bool origem(); //verifica se x=0 e y=0
        bool eixoY()                       { return x == 0 ? 1 : 0; };//verifica se x=0
        bool eixoX()                       { return y == 0 ? 1 : 0; }; // verifica se y=0
};

void Ponto::ler()
{
    cin >> x >> y;
}

bool Ponto::origem()
{
    if ( x == 0 && y == 0 )
        return 1;
    else 
        return 0;
}

string Ponto::obterQuadrante()
{
    if ( origem() )
        return "Origem";
    else if ( eixoY() )
        return "Eixo Y";
    else if ( eixoX() )
        return "Eixo X";
    else if ( x > 0 && y > 0 )
        return "Q1";
    else if ( x > 0 && y < 0 )
        return"Q4";
    else if ( x < 0 && y > 0 )
        return"Q2";
    else
        return"Q3";
}

int main ()
{
    Ponto a;
    a.ler();
    cout << a.obterQuadrante() << endl;
    return 0;
}