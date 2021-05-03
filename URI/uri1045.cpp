#include <iostream>

using namespace std;

class Triangulo
{
    private:
        double A, B, C;
    public:
        void ler();
        void ordenar();
        bool FormaTriangulo();
        string TipoPeloAngulo(); //OBTUSANGULO ACUTANGULO ou RETANGULO
        string TipoPeloLados(); // EQUILATERO, ISOSCELES ou ESCALENO
};

void Triangulo::ler()
{
    cin >> A >> B >> C;
}

void Triangulo::ordenar()
{
    double aux1, aux2;
    if (B >= A && B >= C) {
        aux1 = A;
        A = B;
        B = aux1;
    } else if (C >= A && C >= B) {
        aux1 = A; aux2 = B;
        A = C;
        B = aux1;
        C = aux2;
    }
}

bool Triangulo::FormaTriangulo()
{
    return (A >= B + C) ? 0 : 1;
}

string Triangulo::TipoPeloAngulo()
{
    if ( (A * A) == (B * B) + (C * C) )
        return "TRIANGULO RETANGULO";
    else if ( (A * A) > (B * B) + (C * C) )
        return "TRIANGULO OBTUSANGULO";
    else // if ( (A * A) < (B * B) + (C * C) )
        return "TRIANGULO ACUTANGULO";
}

string Triangulo::TipoPeloLados()
{
    if ( A == B && A == C && B == C )
        return "\nTRIANGULO EQUILATERO\n";
    else if (A == B || A == C || B == C)
        return "\nTRIANGULO ISOSCELES\n";
    else 
        return "\n";
}

int main ()
{
    Triangulo a;
    a.ler();
    a.ordenar();
    if ( a.FormaTriangulo() )
    {
        cout << a.TipoPeloAngulo() << a.TipoPeloLados();
    }
    else 
        cout << "NAO FORMA TRIANGULO" << endl;
    return 0;
}