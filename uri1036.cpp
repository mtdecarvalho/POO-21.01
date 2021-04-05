#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    double a, b, c, x1, x2, delta;
    cin >> a >> b >> c;
    delta = (b*b) - (4*a*c);
    if ( delta > 0 && a != 0 ) {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        cout << setprecision(5) << fixed;
        cout << "R1 = " << x1 << endl;
        cout << "R2 = " << x2 << endl;
    } else 
        cout << "Impossivel calcular" << endl;
    
    return 0;
}