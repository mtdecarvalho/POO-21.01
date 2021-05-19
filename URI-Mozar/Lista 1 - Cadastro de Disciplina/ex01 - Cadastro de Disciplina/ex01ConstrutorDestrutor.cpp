#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Disciplina
{
    private:
        string nome, professor;
        double nota1, nota2;
        int codigo, credito, semestre, ano;
    public:
        Disciplina() {};
        ~Disciplina() {};
        void ler();
        void mostrar();
};

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
}

int main ()
{
    Disciplina *a;
    a->ler();
    a->mostrar();
    return 0;
}