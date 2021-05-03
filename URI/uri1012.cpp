#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    const double pi = 3.14159;
    double a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(3) << fixed;
    cout << "TRIANGULO: " << (a*c) / 2 << endl;
    cout << "CIRCULO: " << pi * pow(c,2) << endl;
    cout << "TRAPEZIO: " << (a+b)*c/2 << endl;
    cout << "QUADRADO: " << pow(b,2) << endl;
    cout << "RETANGULO: " << a*b << endl;

    return 0;
}