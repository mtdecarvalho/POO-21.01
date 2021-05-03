#include <iostream>
#include <iomanip>

using namespace std;

class Notas
{
    private:
        double nota1, nota2;
    public:
        void ler();
        double media();
};

double validar()
{
    double aux;
    do
    {
        cin >> aux;
        if ( aux < 0 || aux > 10 )
            cout << "nota invalida" << endl;
        else
            return aux;
    } while ( aux < 0 || aux > 10);
}

void Notas::ler()
{
    nota1 = validar();
    nota2 = validar();
}

double Notas::media()
{
    return (nota1 + nota2) / 2;
}

int main ()
{
    Notas a;
    double media;
    a.ler();
    cout << setprecision(3);
    cout << "media = " << a.media() << endl;
    return 0;
}