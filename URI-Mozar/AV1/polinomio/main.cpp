#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class TPolinomio
{
    private: 
        int n;
        double c[100], e[100];
    public:
        TPolinomio()  {};
        ~TPolinomio() {};
        void ler();
        double calcular(float x);
};

void TPolinomio::ler()
{
    cin >> n;
    for ( int i = 0 ; i < n ; i++ )
        cin >> c[i] >> e[i];
}

double TPolinomio::calcular( float x )
{
    double total = 0;
    for ( int i = 0 ; i < n ; i++ )
        total += c[i] * pow(x, e[i]);
    return total;
}

int main()
    {
        TPolinomio p;
        float x;
        p.ler();
        cin >> x;
        cout << fixed << setprecision(2);
        cout << "p(" << x << ") = " << p.calcular(x) << endl;
        return 0;
    }