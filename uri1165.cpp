#include <iostream>

using namespace std;

int main () {
    int n, x;
    bool primo;
    cin >> n;
    while (n > 0) {
        cin >> x;
        primo=1;
        for (int i = 2 ; i < x ; i++)
        {
            if ( x % i == 0 ) primo=0;
        }
        if (!primo) cout << x << " nao eh primo" << endl;
        else cout << x << " eh primo" << endl;
        n--;
    }

    return 0;
}