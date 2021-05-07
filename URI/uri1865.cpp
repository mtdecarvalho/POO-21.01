#include <iostream>

using namespace std;

class Pessoa
{
    private:
        string nome;
        int forca;
    public:
        void ler();
        bool ehThor()       { return nome == "Thor"? 1 : 0; }
        string getNome()    { return nome; }
};

void Pessoa::ler()
{
    cin >> nome >> forca;
}

int main()
{   
    Pessoa a;
    int C, i = 0;
    cin >> C;
    while ( i < C )
    {
        a.ler();
        if ( a.ehThor() ) cout << "Y" << endl;
        else cout << "N" << endl;
        i++;
    }

    return 0;
}