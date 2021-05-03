#include <iostream>

using namespace std;

class Triangulo
{
    private:
        double a, b, c;
    public:
        void ler()                  { cin >> a >> b >> c; }
        bool formaTriangulo();
        bool ehRetangulo();
        string tipo();
};

bool Triangulo::formaTriangulo()
{
    if ( a >= b + c || b >= c + a || c >= a + b )
        return 0;
    else 
        return 1;
}

bool Triangulo::ehRetangulo()
{
    if ( (a * a) == (b * b) + (c * c) || (b * b) == (a * a) + (c * c) || (c * c) == (a * a) + (b * b) )
        return 1;
    else
        return 0;
}

string Triangulo::tipo()
{
    if ( a == b && a == c && b == c )
        return "Valido-Equilatero";
    else if ( a == b || a == c || b == c )
        return "Valido-Isoceles";
    else 
        return "Valido-Escaleno";
}

int main ()
{
    Triangulo a;
    a.ler();
    if ( a.formaTriangulo() )
    {
        cout << a.tipo() << endl;
        if ( a.ehRetangulo() ) cout << "Retangulo: S" << endl;
        else cout << "Retangulo: N" << endl;
    }
    else
        cout << "Invalido" << endl;
    return 0;
}