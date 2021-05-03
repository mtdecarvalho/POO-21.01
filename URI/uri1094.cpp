#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int n, coelho = 0, sapo = 0, rato = 0, qtd = 0;
    char tipo;
    cin >> n;
    for (int i = 0 ; i < n ; i++ )
    {
        cin >> qtd >> tipo;
        switch (tipo) {
            case 'C':
                coelho+=qtd;
                break;
            case 'R':
                rato+=qtd;
                break;
            case 'S':
                sapo+=qtd;
                break;
        }
    }
    cout << "Total: " << coelho+rato+sapo << " cobaias" << endl;
    cout << "Total de coelhos: " << coelho << endl;
    cout << "Total de ratos: " << rato << endl;
    cout << "Total de sapos: " << sapo << endl;
    cout << setprecision(2) << fixed;
    cout << "Percentual de coelhos: " << double(coelho * 100) / double(coelho+rato+sapo) << " %" << endl;
    cout << "Percentual de ratos: " << double(rato * 100) / double(coelho+rato+sapo) << " %" << endl;
    cout << "Percentual de sapos: " << double(sapo * 100) / double(coelho+rato+sapo) << " %" << endl;
    return 0;
}