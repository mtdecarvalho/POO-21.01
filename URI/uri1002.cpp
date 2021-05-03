#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    double pi = 3.14159, raio;
    cin >> raio;
    cout << setprecision(4) << fixed;
    cout << "A=" << pi * (raio * raio) << endl;
    return 0;
}