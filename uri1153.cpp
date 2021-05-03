#include <iostream>

using namespace std;

int main () {
    int n, f;
    cin >> n;
    if ( n == 1 || n == 0 ) f = 1;
    else {
        f = n;
        for (int i = 1 ; i < n ; i++)
        {
            f *= i;
        }
    }
    cout << f << endl;

    return 0;
}