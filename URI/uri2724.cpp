#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Elemento
{
    private:
        string simbolo;
        int qtd;
    public:
        string getSimbolo()                                 { return simbolo; }
        int getQtd()                                        { return qtd; }
        void inicializar(string simbolo, int qtd)           { this->simbolo = simbolo; this->qtd = qtd; }
        void inicializar(string simbolo)                    { this->simbolo = simbolo; this->qtd = 1; }
};

class Composto
{
    private:
        Elemento v[100];
        int qtd;
    public:
        void atribuirFormula(string formula);
        bool contemComposto(Composto c);
        void mostrar();
};

class Perigosos
{
    private:
        Composto v[100];
        int qtd;
    public:
        void limpar()                           { qtd = 0;           }
        void inserir(Composto c)                { v[qtd] = c; qtd++; }
        bool prossegue(Composto c);
};

void Composto::atribuirFormula(string formula)
{
    qtd = 0;
    int i, tam;
    tam = formula.length();
    i = 0;
    while ( i < tam )
    {
        char letra = formula[i];
        if (isalpha(letra) && isupper(letra))
        {
            i++;
            string simbolo = "";    
            simbolo += letra;
            int count = 0;
            while ( i < tam && isalpha(formula[i]) && islower(formula[i]) )
            {
                simbolo+=formula[i];
                i++;
            }
            while ( i < tam && isdigit(formula[i]) )
            {
                count = count*10 + formula[i]-'0';
                i++;
            }
            if ( count == 0 )
                count = 1;
            v[qtd].inicializar(simbolo, count);
            qtd++;
        }
        else
            i++;
    }
}

bool Composto::contemComposto( Composto c )
{
    bool achou = false;
    int i = 0, j;

    while ( !achou && i < qtd-c.qtd+1 )
    {
        j = 0;
        achou = true;
        while ( j<c.qtd && achou )
            if ( v[i+j].getSimbolo() != c.v[j].getSimbolo() || v[i+j].getQtd() != c.v[j].getQtd() )
                achou = false;
            else 
                j++;
        i++;
    }
    return achou;
}

void Composto::mostrar()
{
    for(int i=0; i<qtd; i++)
      if (v[i].getQtd()!=1)
        cout << v[i].getSimbolo() << v[i].getQtd() << "-";
      else
        cout << v[i].getSimbolo() << v[i].getQtd() << "-";
    cout << endl;
}

bool Perigosos::prossegue( Composto c )
{
    int i;
    for ( i = 0 ; i < qtd ; i++ )
        if ( c.contemComposto(v[i]) )
            return 1;
    return 0;
}

int main ()
{
    int qtdPerigosos, qtdTestes, qtdExperimentos, i, k, j;
    string s;
    Composto composto;
    Perigosos perigoso;
    cin >> qtdTestes;
    cin.ignore();
    for( i = 0 ; i<qtdTestes ; i++)
    {
        cin >> qtdPerigosos;
        perigoso.limpar(); cin.ignore();
        for ( k = 0 ; k < qtdPerigosos ; k++ )
        {
            getline(cin, s);
            composto.atribuirFormula(s);
            perigoso.inserir(composto);
        }
        cin >> qtdExperimentos; cin.ignore();
        for ( k = 0 ; k < qtdExperimentos ; k++ )
        {
            getline(cin, s);
            composto.atribuirFormula(s);
            if ( perigoso.prossegue(composto) )
                cout << "Abortar" << endl;
            else 
                cout << "Prossiga" << endl;
        }
        if ( i != qtdTestes-1 )
            cout << "\n";
    }
    
    return 0;
}