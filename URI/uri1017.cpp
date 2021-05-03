#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int tempo, velocidade;
    double litros, distancia;
    cin >> tempo >> velocidade;
    distancia = tempo * velocidade;
    litros = distancia / 12;
    cout << setprecision(3) << fixed;
    cout << litros << endl;
    return 0;
}