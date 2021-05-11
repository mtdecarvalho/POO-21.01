#include <iostream>

using namespace std;

int main ()
{
    int N, X[1000], i, menor = 0, posicao = 0;
    cin >> N;
    for ( i = 0 ; i < N ; i++ )
    {
        cin >> X[i];
        if ( i == 0 ) { menor == X[i]; posicao = i; }
        else if ( menor > X[i] ) { menor = X[i]; posicao = i; }
    }
    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << posicao << endl;
    return 0;
}