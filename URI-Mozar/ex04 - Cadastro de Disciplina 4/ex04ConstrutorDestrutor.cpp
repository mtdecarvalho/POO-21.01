#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>

using namespace std;

class Disciplina
{
    private:
        string nome, professor;
        double nota1, nota2, media;
        int codigo, credito, semestre, ano;
    public:
        Disciplina()            {};
        ~Disciplina()           {};
        void ler();
        void mostrar();
        string getNome()        { return nome;      }
        string getProfessor()   { return professor; }
        int getCodigo()         { return codigo;    }
        int getAno()            { return ano;       }
        int getSemestre()       { return semestre;  }
        double getMedia()       { return media;     }
        int getCredito()        { return credito;   }
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
    media = (nota1 + 2.0*nota2)/3.0;
}

void Disciplina::mostrar()
{
    cout << right << setfill('0') << setw(4) << codigo << " ";
    cout << left << setfill(' ') << setw(50) << nome << " ";
    cout << right << setfill(' ') << setw(4) << credito << " ";
    cout << left << setw(4) << ano << "/" << setw(1) << semestre << " ";
    cout << setprecision(2) << fixed;
    cout << right << setfill('0') << setw(5) << media << endl;
};

class Historico
{
    private:
        Disciplina* v[1000];
        int qtd;
        double cr;
    public:
        Historico()            { qtd = 0; }
        ~Historico();
        void limpar()          { qtd = 0; cr = 0; }
        int indice();
        void calculoCR();
        void inserirDisciplina();
        void removerDisciplina();
        void alterarDisciplina();
        void listarDisciplinas();
        void listarPorAnoSemestre();
        void listarPorNomeProfessor();
        void mostrarHistorico();
};

Historico::~Historico()
{
    for ( int i = 0 ; i < qtd ; i++ )
        delete v[i];
}

void Historico::inserirDisciplina()
{
    Disciplina *d = new Disciplina();
    d->ler();
    v[qtd] = d;
    qtd++;
}

int Historico::indice()
{
    int codigo, i = 0;
    bool achou = 0;
    cin >> codigo;
    while ( !achou && i < qtd )
    {
        if ( v[i]->getCodigo() == codigo )
            achou = 1;
        else 
            i++;
    }
    return achou ? i : -1;
}

void Historico::calculoCR()
{
    int i;
    double pesoTotal = 0;
    cr = 0;
    for ( i = 0 ; i < qtd ; i++ )
    {
        pesoTotal += v[i]->getCredito();
        cr += v[i]->getMedia()*v[i]->getCredito();
    }
    if ( cr > 0 )
        cr /= pesoTotal;
}

void Historico::removerDisciplina()
{
    int posicao = indice();
    int i;
    if ( posicao > -1 )
    {
        for ( i = posicao+1 ; i < qtd ; i++, posicao++ )
        {
            v[posicao] = v[i];
        }
        qtd--;
        cout << "Disciplina removida com sucesso!" << endl;
    }
    else 
        cout << "Disciplina nao encontrada!" << endl;
}

void Historico::alterarDisciplina()
{
    int posicao = indice();
    if ( posicao > -1 )
    {
        Disciplina *d = new Disciplina();
        d->ler();
        delete v[posicao];
        v[posicao] = d;
        cout << "Disciplina alterada com sucesso!" << endl;
    }
    else 
        cout << "Disciplina nao encontrada!" << endl;
}

bool esperaOk( string linha )
{
    return linha == "Ok" ? 1 : 0;
}

void Historico::listarDisciplinas()
{
    int i;
    string linha = " ";
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for ( i = 0 ; i < qtd ; i++ )
    {
        Disciplina *d = v[i];
        d->mostrar();
    }
    while ( !esperaOk(linha) )
        cin >> linha;
}

void Historico::listarPorAnoSemestre()
{
    int anoFiltro, semestreFiltro, posicao, i;
    string linha = " ";
    cin >> anoFiltro >> semestreFiltro;
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for ( i = 0 ; i < qtd ; i++ )
    {
        Disciplina *d = v[i];
        if ( d->getAno() == anoFiltro && d->getSemestre() == semestreFiltro )
            d->mostrar();
    }
    while ( !esperaOk(linha) )
        cin >> linha;
}

void Historico::listarPorNomeProfessor()
{
    string filtro;
    string linha = " ";
    int i;
    cin.ignore();
    getline(cin, filtro);
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for ( i = 0 ; i < qtd ; i++ )
    {
        Disciplina *d = v[i];
        if ( d->getNome().find(filtro) != string::npos || d->getProfessor().find(filtro) != string::npos ) // achou
            d->mostrar();
    }
    while ( !esperaOk(linha) )
        cin >> linha;
}

void Historico::mostrarHistorico()
{
    int i;
    string linha = " ";
    calculoCR();
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for ( i = 0 ; i < qtd ; i++ )
        v[i]->mostrar();
    cout << setprecision(2) << fixed;
    cout << left << setfill(' ') << setw(68) << "Coeficiente de Rendimento";
    cout << right << setfill('0') << setw(5) << cr << endl;
    while ( !esperaOk(linha) )
        cin >> linha;
}

int menu()
{
    int opcao;
    cout << "1 - inserir nova disciplina\n"
            "2 - remover disciplina pelo codigo\n"
            "3 - alterar disciplina pelo codigo\n"
            "4 - listar todas as disciplinas\n"
            "5 - listar disciplinas de um ano/semestre\n"
            "6 - listar disciplinas pelo nome/professor\n"
            "7 - Historico\n"
            "8 - sair\n"
            "Entre com a sua opcao:" << endl;
    cin >> opcao;
    return opcao;
}

int main ()
{
    Disciplina *d;
    Historico b;
    bool fim = 0;
    while ( !fim )
    {
        switch( menu() )
        {
            case 1:
                b.inserirDisciplina();
                cout << "Disciplina inserida com sucesso!" << endl;
                break;
            case 2:
                b.removerDisciplina(); break;
            case 3:
                b.alterarDisciplina(); break;
            case 4:
                b.listarDisciplinas(); break;
            case 5:
                b.listarPorAnoSemestre(); break;
            case 6:
                b.listarPorNomeProfessor(); break;
            case 7:
                b.mostrarHistorico(); break;
            case 8:
                cout << "Obrigado por utilizar o programa de cadastro, volte sempre!" << endl; fim = 1;
                break;
            default:
                break;
        }
    }
    
    return 0;
}