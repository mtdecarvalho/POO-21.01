#include <iostream>

using namespace std;

int main()
{
    int N, T[100], i, menor = 1;
    cin >> N;
    for ( i = 1 ; i <= N ; i++ )
        cin >> T[i];
    for ( i = 1 ; i <= N ; i++ )
    {
        if ( T[menor] > T[i] )
            menor = i;
    }
    cout << menor << endl;
    return 0;
}