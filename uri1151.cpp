#include <iostream>

using namespace std;

int main () {
    int n, n1, n2, a;
    cin >> a;
    n1 = 0; n2 = 1;
    for (int i = 0 ; i < a ; i++)
    {
        if ( i == 0 ) cout << n1;
        else if ( i == 1 ) cout << n2;
        if ( i > 1 ) {
            n = n1 + n2;
            n1 = n2;
            n2 = n;
            cout << n;
        }
        if ( i != a-1 ) cout << " ";
        else cout << endl;
    }

    return 0;
}