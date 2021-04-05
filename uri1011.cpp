#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    const double pi = 3.14159;
    double a;
    cin >> a;
    cout << setprecision(3) << fixed;
    cout << "VOLUME = " << (4.0/3) * pi * pow(a,3)  << endl;

    return 0;
}