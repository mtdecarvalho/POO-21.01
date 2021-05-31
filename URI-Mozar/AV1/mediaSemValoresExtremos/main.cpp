#include <iostream>
#include <iomanip>

using namespace std;

class TVet
{
    private:
        int qtd;
        double v[100];
    public:
        TVet() { qtd = 0; }
        ~TVet() {};
        void ler();
        void imprimir();
        double maior()  { return v[qtd-1]; }
        double menor()  { return v[0]; }
        double mediaEx();
};

int comparar (const void * a, const void * b) // crescente
{
    if ( *(double*)a <  *(double*)b ) return -1;
    if ( *(double*)a == *(double*)b ) return 0;
    if ( *(double*)a >  *(double*)b ) return 1;
}

void TVet::ler()
{
    cin >> qtd;
    for ( int i = 0 ; i < qtd ; i++ )
        cin >> v[i];
    qsort(v, qtd, sizeof(double), comparar);
}

double TVet::mediaEx()
{
    int k = 0;
    double media = 0;
    for ( int i = 1 ; i < qtd-1 ; i++ )
        if ( v[i] != v[qtd-1] && v[i] != v[0] ) // se diferente de maior e menor
        {
            media += v[i];
            k++;
        }
    media /= k;
    return media;
}

int main()
{
    TVet v;
    v.ler();
    cout << fixed << setprecision(2);
    cout << "Maior: "<< v.maior() << endl;
    cout << "Menor: "<< v.menor() << endl;
    cout << "Media sem extremos: "<< v.mediaEx() << endl;
    return 0;
}