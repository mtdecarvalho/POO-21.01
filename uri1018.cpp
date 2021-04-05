#include <iostream>

using namespace std;

int main () {
    int valor, cem, cinq, vinte, dez, cinco, dois, um;
    cin >> valor;
    cem = valor / 100;
    cinq = (valor - (cem*100)) / 50;
    vinte = (valor - (cem*100 + cinq*50)) / 20;
    dez = (valor - (cem*100 + cinq*50 + vinte*20)) / 10;
    cinco = (valor - (cem*100 + cinq*50 + vinte*20 + dez*10)) / 5;
    dois = (valor - (cem*100 + cinq*50 + vinte*20 + dez*10 + cinco*5)) / 2;
    um = (valor - (cem*100 + cinq*50 + vinte*20 + dez*10 + cinco*5 + dois*2)) / 1;
    cout << valor << endl;
    cout << cem << " nota(s) de R$ 100,00" << endl;
    cout << cinq << " nota(s) de R$ 50,00" << endl;
    cout << vinte << " nota(s) de R$ 20,00" << endl;
    cout << dez << " nota(s) de R$ 10,00" << endl;
    cout << cinco << " nota(s) de R$ 5,00" << endl;
    cout << dois << " nota(s) de R$ 2,00" << endl;
    cout << um << " nota(s) de R$ 1,00" << endl;
    return 0;
}