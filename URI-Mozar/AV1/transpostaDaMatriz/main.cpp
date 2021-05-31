#include <iostream>

using namespace std;

class TMatriz
{
    private:
        int n, m;
        char v[100][100];
    public:
        TMatriz() {};
        void ler();
        void transposta();
        void mostrar();
};

void TMatriz::ler()
{
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++ )
        for ( int k = 0 ; k < m ; k++ )
            cin >> v[i][k];
}

void TMatriz::transposta()
{
    char copia[100][100];
    int aux;

    for ( int i = 0 ; i < m ; i++ )
        for ( int k = 0 ; k < n ; k++ )
            copia[i][k] = v[k][i];
    
    aux = n; n = m; m = aux;
    for ( int i = 0 ; i < n ; i++ )
        for ( int k = 0 ; k < m ; k++ )
            v[i][k] = copia[i][k];
}

void TMatriz::mostrar()
{
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int k = 0 ; k < m ; k++ )
            cout << v[i][k];
        cout << endl;
    }
            
}

int main()
    {
        TMatriz a;
	a.ler();
	a.transposta();
        a.mostrar();
        return 0;
    }