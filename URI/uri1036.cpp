#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Eq2Grau
{
    private:
        double a, b, c;
    public:
        void ler();
        double delta();
        int raizes(double delta);
        double raiz1(double delta);
        double raiz2(double delta);
};

void Eq2Grau::ler()
{
    cin >> a >> b >> c;
}

double Eq2Grau::delta()
{
    return (b*b) - (4 * a * c);
}

int Eq2Grau::raizes( double delta )
{
    if ( delta > 0 )
        return 2;
    else if ( delta == 0 )
        return 1;
    else
        return 0;
}

double Eq2Grau::raiz1( double delta )
{
    if ( a > 0 )
        return (-b + sqrt(delta)) / (2*a);
    else 
        return 0;
}

double Eq2Grau::raiz2( double delta )
{
    if ( a > 0 )
        return (-b - sqrt(delta)) / (2*a);
    else 
        return 0;
}

int main () {
    Eq2Grau a;
    double delta, x1, x2;
    int raizes;
    a.ler();
    delta = a.delta(); raizes = a.raizes( delta );
    x1 = a.raiz1( delta );
    x2 = a.raiz2( delta );
    if ( raizes == 0 || x1 == 0 || x2 == 0 )
        cout << "Impossivel calcular" << endl;
    else 
    {
        cout << setprecision(5) << fixed;
        cout << "R1 = " << x1 << endl;
        cout << "R2 = " << x2 << endl;
    }
    return 0;
}