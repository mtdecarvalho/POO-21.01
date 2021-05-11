#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    double N, K = 0, i;
    cin >> N;
    for ( i = 0 ; i < N ; i++ )
    {
        K += 6;
        K = 1 / K;
    }
    K+=3;
    cout << setprecision(10) << fixed;
    cout << K << endl;
    return 0;
}