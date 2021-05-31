#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Aluno
{
    private:
        string nome;
        double nota1, nota2, media;
        bool aprovado;
    public:
        Aluno()                 { aprovado = 0; media = 0; }
        ~Aluno()                {}
        void ler();
        void calcularMedia()            { media = (nota1 + 2*nota2)/3; }
        void foiAprovado()      { media >= 6 ? aprovado = 1 : aprovado = 0; }
        string getNome()        { return nome;  }
        double getMedia()       { return media; }
        string getAprovado()    { return aprovado ? "Aprovado" : "Reprovado"; }
};

void Aluno::ler()
{
    cin.ignore();
    getline(cin, nome);
    cin >> nota1 >> nota2;
}

class TTurma
{
    private:
        Aluno v[100];
        int qtd;
    public:
        TTurma()  { qtd = 0; }
        ~TTurma() {}
        void ler();
        void listar();
};

void TTurma::ler()
{
    cin >> qtd;
    for ( int i = 0 ; i < qtd ; i++ )
    {
        v[i].ler();
        v[i].calcularMedia();
        v[i].foiAprovado();
    }
}

void TTurma::listar()
{
    for ( int i = 0 ; i < qtd ; i++ )
    {
        cout << setprecision(2) << fixed;
        cout << setw(50) << setfill(' ') << left << v[i].getNome() << setw(6)
        << right << v[i].getMedia() << " " << v[i].getAprovado() << endl;
    }
}

int main()
    {
        TTurma t;
	t.ler();
        t.listar();
        return 0;
    }