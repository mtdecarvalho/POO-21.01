#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>

using namespace std;

class Disciplina
{
    private:
        string nome, professor;
        double nota1, nota2;
        int codigo, credito, semestre, ano;
    public:
        Disciplina()  {};
        ~Disciplina() {};
        void ler();
        void mostrar();
};

bool esperaOk( string linha )
{
    return linha == "Ok" ? 1 : 0;
}

void Disciplina::ler()
{
    cin >> codigo;
    cin.ignore();
    getline(cin, nome);
    getline(cin, professor);
    cin >> credito;
    cin >> ano;
    cin >> semestre;
    cin >> nota1;
    cin >> nota2;   
}

void Disciplina::mostrar()
{
    string linha;
    cout << "Codigo    : " << setfill('0') << setw(4) << codigo << endl;
    cout << "Nome      : " << nome << endl;
    cout << "Professor : " << professor << endl;
    cout << "Creditos  : " << credito << endl;
    cout << "Ano       : " << ano << endl;
    cout << "Semestre  : " << semestre << endl;
    cout << setprecision(2) << fixed;
    cout << "Nota1     : " << nota1 << endl;
    cout << "Nota2     : " << nota2 << endl;
    cout << "Media     : " << (nota1 + 2.0*nota2)/3.0 << endl;
    while ( !esperaOk(linha) )
    {
        cin.ignore();
        getline(cin, linha);
    }
};

int main ()
{
    Disciplina *a;
    int opcao;
    while ( opcao != 3 )
    {
        cout << "1 - ler dados da disciplina\n2 - mostrar os dados da disciplina\n3 - sair\nEntre com a sua opcao:" << endl;
        cin >> opcao;
        switch (opcao)
        {
            case 1:
                a->ler();
                break;
            case 2:
                a->mostrar();
                break;
            case 3:
                cout << "Obrigado por utilizar o programa de cadastro, volte sempre!" << endl;
                return 0;
            default:
                break;
        }
    }
    return 0;
}