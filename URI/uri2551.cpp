#include <iostream>

using namespace std;

class Treino
{
    private:
        double t, d, vm;
    public:
        void ler()      { cin >> t >> d; vm = d / t; }
        double getVM()  { return vm;                 }
};

int main ()
{
    Treino t[30];
    int N, i;
    double recordeAnterior;
    while ( cin >> N )
    {
        for ( i = 0 ; i < N ; i++ )
            t[i].ler();
        cout << 1 << endl; recordeAnterior = t[0].getVM();
        for ( i = 1 ; i < N ; i++ )
            if ( recordeAnterior < t[i].getVM() ) { recordeAnterior = t[i].getVM(); cout << i+1 << endl; }
    }
    return 0;
}