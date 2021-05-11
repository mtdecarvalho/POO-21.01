#include <iostream>

using namespace std;

int comparar(const void * a, const void * b)
{
    return *(int*)b - *(int*)a; // ordernar decrescentemente
}

int main ()
{
    int notas[1000], qtd = 0, classificados, cont = 0, i;
    cin >> qtd;
    cin >> classificados;
    for ( i = 0 ; i < qtd ; i++ )
        cin >> notas[i];
    qsort(notas, qtd, sizeof(int), comparar);
    for ( i = 0 ; cont < classificados ; i++ )
    {
        if ( i != classificados-1 ) cont++;
        else if ( notas[i+1] == notas[i] ) { cont++; classificados++; }
    }
    cout << cont << endl;
    return 0;
}