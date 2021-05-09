#include <iostream>

using namespace std;

string decimalParaHexadecimal( int V )
{
    string hex = "";
    int v[100], i = 0, qtd = 0;
    while ( V >= 16 )
    {
        v[i] = V % 16;
        V /= 16;
        i++;
        qtd = i;
    }
    v[i] = V; i++;
    for ( i = qtd ; i >= 0 ; i-- )
        switch ( v[i] )
        {
            case 0: hex.append("0"); break;
            case 1: hex.append("1"); break;
            case 2: hex.append("2"); break;
            case 3: hex.append("3"); break;
            case 4: hex.append("4"); break;
            case 5: hex.append("5"); break;
            case 6: hex.append("6"); break;
            case 7: hex.append("7"); break;
            case 8: hex.append("8"); break;
            case 9: hex.append("9"); break;
            case 10: hex.append("A"); break;
            case 11: hex.append("B"); break;
            case 12: hex.append("C"); break;
            case 13: hex.append("D"); break;
            case 14: hex.append("E"); break;
            case 15: hex.append("F"); break;
        }
    return hex;
}

int main()
{
    int V, v[100], i = 0;
    string hex;
    cin >> V;
    hex = decimalParaHexadecimal(V);
    cout << hex << endl;
    return 0;
}