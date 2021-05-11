#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int n, pedido, qtd;
    double total = 0;
    cin >> n;
    while ( n > 0 )
    {
        cout << setprecision(2) << fixed;
        cin >> pedido;
        switch ( pedido )
        {
            case 1001: cin >> qtd; total += 1.50 * qtd; break;
            case 1002: cin >> qtd; total += 2.50 * qtd; break;
            case 1003: cin >> qtd; total += 3.50 * qtd; break;
            case 1004: cin >> qtd; total += 4.50 * qtd; break;
            case 1005: cin >> qtd; total += 5.50 * qtd; break;
        }
        n--;
    }
    cout << total << endl;
    return 0;
}