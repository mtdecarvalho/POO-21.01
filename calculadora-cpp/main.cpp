#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool ehNegativo ( double x )
{
    return x < 0 ? 1 : 0;
}

bool temZero( double x )
{
    return x == 0 ? 1 : 0;
}

class OperacoesBasicas
{
    private:
        double x, y, resultado;
    public:
        OperacoesBasicas()  {};
        ~OperacoesBasicas() {};
        void ler()                  { cin >> x >> y;        }
        void soma()                 { resultado = x + y;    }
        void subtracao()            { resultado = x - y;    }
        void multiplicacao()        { resultado = x * y;    }
        void divisao()              { resultado = x / y;    }
        void potencia()             { resultado = pow(x,2); }
        void radiciacao();  
        void imprimirResultado();
        double getX()               { return x;             }
        double getY()               { return y;             }
        double getResultado()       { return resultado;     }
};

void OperacoesBasicas::imprimirResultado()
{
    string str = to_string(resultado);
    int i;
    bool achouPonto = 0, achouNumero = 0;
    for ( i = 0 ; i < str.length() && !achouNumero ; i++ )
    {
        if ( achouPonto )
            if ( str[i] != '0' )
                achouNumero = 1;
        if ( str[i] == '.') achouPonto = 1;
    }
    if ( achouNumero )  cout << setprecision(2) << fixed;
    else if ( !achouNumero ) cout << setprecision(0) << fixed;
    cout << resultado << endl;
}

class Eq2Grau
{
    private:
        double a, b, c, delta, x1, x2;
    public:
        Eq2Grau()  {};
        ~Eq2Grau() {};
        void ler();
        double calculoDelta()                { return (b*b) - (4*a*c); }
        void calcular();
        void imprimirResultado()      { cout << "x¹ = " << x1 << " " << "x² = " << x2 << endl; }
};

void Eq2Grau::ler()
{
    cout << "Insira os valores de a, b e c, respectivamente:" << endl; 
    cout << "Exemplo: 1 -1 4" << endl;
    cin >> a >> b >> c;
}

void Eq2Grau::calcular()
{
    double delta = calculoDelta();
    x1 = (-b + sqrt( delta ) ) / (2*a);
    x2 = (-b - sqrt( delta ) ) / (2*a);
}


int menu()
{
    int k;
    cout << "Calculadora" << endl;
    cout << "1 - Soma" << endl;
    cout << "2 - Subtracao" << endl;
    cout << "3 - Multiplicacao" << endl;
    cout << "4 - Divisao" << endl;
    cout << "5 - Equacao de Segundo Grau" << endl;
    cin >> k;
    return k;
}


int main()
{
    OperacoesBasicas a;
    Eq2Grau b;
    int opcao = -1;
    while ( opcao != 0 )
    {
        switch ( menu() )
        {
            case 1:
                a.ler(); a.soma(); a.imprimirResultado(); break;
            case 2:
                a.ler(); a.subtracao(); a.imprimirResultado(); break;
            case 3:
                a.ler(); a.multiplicacao(); a.imprimirResultado(); break;
            case 4:
                a.ler(); 
                while ( temZero( a.getX() ) || temZero( a.getY() ) )
                {
                    cout << "Valores invalidos, tente novamente." << endl;
                    a.ler();
                }
                a.divisao();
                cout << a.getResultado() << endl; break;
            case 5:
                b.ler();
                b.calcular();
                b.imprimirResultado();
                break;
            case 0:
                cout << "Fim" << endl; break;
        }
    }
    return 0;
}