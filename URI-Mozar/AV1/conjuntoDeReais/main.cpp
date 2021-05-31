#include <iostream>

using namespace std;

class TConjunto
{
    private:
        int linhas, qtd;
        double v[100];
    public: 
        TConjunto()  { qtd = 0; }
        ~TConjunto() {}
        void ler();
        void mostrar();
        bool estacontido( TConjunto a );
        bool contem( TConjunto a );
        bool pertence( double x );
        void uniao( TConjunto a, TConjunto b );
        void intersecao( TConjunto a, TConjunto b );
        void subtracao( TConjunto a, TConjunto b );
        int getQtd()                    { return qtd; }
        double getNum( int i )          { return v[i]; }
};

bool TConjunto::pertence( double numero )
{
    for ( int i = 0 ; i < qtd ; i++ )
        if ( numero == v[i] )
            return 1;
    return 0;
}

void TConjunto::ler()
{
    double numero;
    cin >> linhas;
    for ( int i = 0 ; i < linhas ; i++ )
    {
        cin >> numero;
        if ( i == 0 )
        {
            v[qtd] = numero;
            qtd++;
        }
        else
        {
            if ( !pertence(numero) )
            {
                v[qtd] = numero;
                qtd++;
            }
        }
    }
}

void TConjunto::mostrar()
{
    for ( int i = 0 ; i < qtd ; i++ )
    {
        cout << v[i];
        if ( i != qtd-1 ) cout << " ";
    }
    cout << endl;
}

void TConjunto::uniao( TConjunto a, TConjunto b )
{
    qtd = a.getQtd();
    for ( int i = 0 ; i <= a.getQtd() ; i++ )
        v[i] = a.getNum(i);
    for ( int i = 0 ; i < b.getQtd() ; i++ )
    {
        if ( !pertence( b.getNum(i) ) )
        {
            v[qtd] = b.getNum(i);
            qtd++;
        }
    }
}

void TConjunto::intersecao( TConjunto a, TConjunto b )
{
    qtd = 0;
    for ( int i = 0 ; i <= a.getQtd() ; i++ )
    {
        if ( b.pertence(a.getNum(i)) )
        {
            v[qtd] = a.getNum(i);
            qtd++;
        }
    }
}

void TConjunto::subtracao( TConjunto a, TConjunto b )
{
    qtd = 0;
    for ( int i = 0 ; i < a.getQtd() ; i++ )
    {
        if ( !b.pertence( a.getNum(i) ) )
        {
            v[qtd] = a.getNum(i);
            qtd++;
        }
    }
}

bool TConjunto::estacontido( TConjunto a )
{
    int cont = 0;
    for ( int i = 0 ; i < qtd ; i++ )
        if ( a.pertence(v[i]) )
            cont++;
    return cont == qtd ? 1 : 0;
}

bool TConjunto::contem( TConjunto a )
{
    int cont = 0;
    for ( int i = 0 ; i < qtd ; i++ )
        if ( a.pertence(v[i]) )
            cont++;
    return cont == a.getQtd() ? 1 : 0;
}

    int main()
    {
        TConjunto a,b,c,d,e;
        int x;
        a.ler();
        b.ler();
        c.uniao(a,b);
        cout << "a UNIAO b = ";
        c.mostrar();
        d.intersecao(a,b);
        cout << "a INTERSECAO b = ";
        d.mostrar();
        cout << "d esta contido em a: " << (d.estacontido(a)?"sim":"nao") << endl;
        cout << "a contem d: " << (a.contem(d)?"sim":"nao") << endl;
        cout << "c esta contido em a: " << (c.estacontido(a)?"sim":"nao") << endl;
        cout << "c contem a: " << (c.contem(a)?"sim":"nao") << endl;
        cout << "c contem b: " << (c.contem(b)?"sim":"nao") << endl;
        cout << "a contem b: " << (a.contem(b)?"sim":"nao") << endl;
        cout << "a esta contido em b: " << (a.estacontido(b)?"sim":"nao") << endl;
        cout << "a - b = ";
        e.subtracao(a,b);
        e.mostrar();
        cin >> x;
        while (x>0){
            cout << x << " pertence ao conjunto A: " << (a.pertence(x)?"sim":"nao") << endl;
            cin >> x;
        }
        return 0;
    }