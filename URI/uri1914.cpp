#include <iostream>

using namespace std;

class Pessoa
{
    private:
        string nome, escolha;
    public:
        void ler()              { cin >> nome >> escolha; }
        string getNome()        { return nome;            }
        string getEscolha()     { return escolha;         }
};

int main()
{
    Pessoa a, b;
    int QT, N, M;
    cin >> QT;
    for ( int i = 0 ; i < QT ; i++ )
    {
        a.ler(); b.ler();
        cin >> N >> M;
        if ( (N + M) % 2 == 0 ) // par
        {
            if ( a.getEscolha() == "PAR" )
                cout << a.getNome() << endl;    
            else if ( b.getEscolha() == "PAR" )
                cout << b.getNome() << endl;
        }
        else 
        {
            if ( a.getEscolha() == "IMPAR" )
                cout << a.getNome() << endl;
            else if ( b.getEscolha() == "IMPAR" )
                cout << b.getNome() << endl;
        }
    }
    return 0;
}