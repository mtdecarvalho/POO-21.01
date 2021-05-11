#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14

int main ()
{
    double V, D;
    while ( cin >> V >> D )
    {
        cout << setprecision(2) << fixed;
        cout << "ALTURA = " << V / ( PI*( (D/2) * (D/2) ) ) << "\nAREA = " << PI*( (D/2) * (D/2) ) << endl;
    }
    return 0;
}