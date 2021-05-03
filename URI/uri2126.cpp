#include <iostream>
#include <string>

using namespace std;

class Subsequencia
{
    private:
        string texto;
    public:
        void setTexto()                         { cin >> texto; }
        void Ocorrencias(string substr, int *ocorrencias, int *ultimapos);
};

void Subsequencia::Ocorrencias(string substr, int *ocorrencias, int *ultimapos)
{
    int i = 0;// ocorrencias = 0, ultimapos;
    for ( i = texto.find(substr, 0) ; i != string::npos ; i = texto.find(substr, i) )
    {
        *ocorrencias+=1;
        *ultimapos = i;
        i++;
    }
}

int main ()
{
    Subsequencia a;
    string substring;
    int contador = 0, ocorrencias, ultimapos;
    while ( cin >> substring )
    {
        ocorrencias = 0; ultimapos = 0;
        a.setTexto();
        cout << "Caso #" << contador+1 << ":" << endl;
        a.Ocorrencias(substring, &ocorrencias, &ultimapos);
        if ( ocorrencias == 0 )
            cout << "Nao existe subsequencia" << endl;
        else 
        {
            cout << "Qtd.Subsequencias: " << ocorrencias << endl;
            cout << "Pos: "<< ultimapos+1 << endl;
        }
        cout << endl;
        contador++;
    }
    return 0;
}