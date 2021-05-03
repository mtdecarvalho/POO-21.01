#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    double a[6], media = 0;
    int cont = 0;
    for (int i = 0 ; i < 6 ; i++ ) {
        cin >> a[i];
        if ( a[i] > 0 ) {
            cont++; 
            media += a[i];
        }
    }
    media /= cont;
    cout << cont << " valores positivos" << endl;
    cout << setprecision(2) << media << endl;
    return 0;
}