#include <iostream>

using namespace std;

class TVetInt
{
    private: 
        int n, m[20000];
    public:
        void ler();
        void inverter();
        void listar();
};

void TVetInt::ler()
{
    cin >> n;
    for (int i = 0 ; i < n ; i++ )
        cin >> m[i];
}

void TVetInt::inverter()
{
    int aux;
    for ( int i = 0, k = n-1 ; i < n/2 ; i++, k-- )
    {
        aux = m[i];
        m[i] = m[k];
        m[k] = aux;
    }
}

void TVetInt::listar()
{
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << m[i];
        if ( i != n-1 ) cout << " ";

    }
    cout << endl;
}

int main()
    {
        TVetInt v;
	v.ler();
	v.inverter();
	v.listar();
        return 0;
    }