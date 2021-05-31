#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class TPoligono
{
    private:
        int n;
        double x[100], y[100];
    public:
        TPoligono()  {}
        ~TPoligono() {};
        void ler();
        double perimetro();
};

void TPoligono::ler()
{
    cin >> n;
    for ( int i = 0 ; i < n ; i++ )
        cin >> x[i] >> y[i];
}

double TPoligono::perimetro()
{
    double perimetro = 0;
    int i;
    for ( i = 1 ; i < n ; i++ )
    {
        perimetro += sqrt( pow( ( x[i] - x[i-1] ) ,2) + pow( ( y[i] - y[i-1] ) ,2) );
    }
    perimetro += sqrt( pow( ( x[i-1] - x[0] ) ,2) + pow( ( y[i-1] - y[0] ) ,2) );
    cout << setprecision(2) << fixed;
    return perimetro;
}


int main()
    {
        TPoligono p;
	p.ler();
        cout << "perimetro - " << p.perimetro() << endl;
        return 0;
    }