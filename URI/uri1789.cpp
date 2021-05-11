#include <iostream>

using namespace std;

int main ()
{
    int L, velocidade, maiorVelocidade, i;
    while ( cin >> L )
    {
        for ( i = 0 ; i < L ; i++ )
        {
            cin >> velocidade;
            if ( i == 0 ) maiorVelocidade = velocidade;
            else if ( velocidade > maiorVelocidade ) maiorVelocidade = velocidade;
        }
        if ( maiorVelocidade < 10 )
            cout << "1" << endl;
        else if ( 20 > maiorVelocidade >= 10)
            cout << "2" << endl;
        else if ( maiorVelocidade >= 20 )
            cout << "3" << endl;
    }
    return 0;
}