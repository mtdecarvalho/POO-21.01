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
        void ler();
        void mostrar();
};

class Historico
{
    private:
        Disciplina v[10];
        int qtd;
    public:
        void inicializar()          { qtd = 0; }
        void inserirDisciplina()    { v[qtd].ler(); qtd++; }
        void mostrarHistorico();
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
    cout << right << setfill('0') << setw(4) << codigo << " ";
    cout << left << setfill(' ') << setw(50) << nome << " ";
    cout << right << setfill(' ') << setw(4) << credito << " ";
    cout << left << setw(4) << ano << "/" << setw(1) << semestre << " ";
    cout << setprecision(2) << fixed;
    cout << right << setfill('0') << setw(5) << (nota1 + 2.0*nota2)/3.0 << endl;
};

void Historico::mostrarHistorico()
{
    int i;
    string linha;
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for ( i = 0 ; i < qtd ; i++ )
        v[i].mostrar();
    while ( !esperaOk(linha) )
    {
        cin.ignore();
        getline(cin, linha);
    }
}

int main ()
{
    Disciplina a;
    Historico b;
    int opcao;
    b.inicializar();
    while ( opcao != 4 )
    {
        cout << "1 - inicializar\n2 - inserir nova disciplina\n3 - listar historico\n4 - sair\nEntre com a sua opcao:" << endl;
        cin >> opcao;
        switch (opcao)
        {
            case 1:
                b.inicializar();
                cout << "Historico inicializado com sucesso!" << endl;
                break;
            case 2:
                b.inserirDisciplina();
                cout << "Disciplina inserida com sucesso!" << endl;
                break;
            case 3:
                b.mostrarHistorico();
                break;
            case 4:
                cout << "Obrigado por utilizar o programa de cadastro, volte sempre!" << endl;
                return 0;
            default:
                break;
        }
    }
    return 0;
}