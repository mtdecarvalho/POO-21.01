#include <iostream>

using namespace std;

int main () {
    int n, x, s;
    cin >> n;
    while ( n > 0 ) {
        cin >> x;
        for ( int i = 1 ; i < x ; i++ )
        {
            if ( x % i == 0 )
            {
                s += i;
            }
        }
        cout << x;
        if ( s == x ) cout << " eh perfeito" << endl;
        else cout << " nao eh perfeito" << endl;
        s = 0; n--;
    }

    return 0;
}