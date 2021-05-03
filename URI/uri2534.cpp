#include <iostream>
#include <cstdlib>

using namespace std;

int comparar(const void * a, const void * b)
{
    const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x < *y)
		return 1;
	else if (*x > *y)
		return -1;

	return 0;
}

class Vetor
{
    private:
        int v[100], qtd;
    public:
        void ler(int N);
        void ordenar()          { qsort(v, qtd, sizeof(int), comparar); }
        int obterNota(int i)    { return v[i]; }

};


void Vetor::ler(int N)
{
    qtd = N;
    for ( int i = 0 ; i < qtd ; i++ )
        cin >> v[i];
}

int main ()
{
    Vetor a;
    int N, Q, i;
    while ( cin >> N >> Q )
    {
        a.ler(N); a.ordenar();
        for ( int k = 0 ; k < Q ; k++ )
        {
            cin >> i;
            cout << a.obterNota(i-1) << endl;
        }
    }
    return 0;
}