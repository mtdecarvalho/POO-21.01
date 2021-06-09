#include "Historico.h"
#include "DisciplinaTipo1.h"
#include "DisciplinaTipo2.h"
#include "DisciplinaTipo3.h"

#include <iomanip>

using namespace std;

Disciplina* criarDisciplina()
{
    int tipo;
    do
    {
        cout << "Selecione o tipo de disciplina:" << endl <<
                "1 - Tipo 1" << endl <<
                "2 - Tipo 2" << endl <<
                "3 - Tipo 3" << endl <<
                "Entre com a escolha: ";
        cin >> tipo;
    } while ( tipo < 1 || tipo > 3);
    switch (tipo)
    {
        case 1: return new Tipo1();
        case 2: return new Tipo2();
        case 3: return new Tipo3();
        default:
            cout << "deu ruim"; exit(0);
    }
}

Historico::Historico()
{
    qtd = 0;
}

Historico::~Historico()
{
    for ( int i = 0 ; i < qtd ; i++ )
        delete v[i];
}

int Historico::obterIndice()
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

void Historico::inserir()
{
    v[qtd] = criarDisciplina();
    v[qtd]->ler();
    qtd++;
}

void Historico::remover()
{
    int achou = obterIndice();
    if ( achou > -1 )
    {
        delete v[achou];
        v[achou] = v[qtd-1];
        qtd--;
    }   
    else 
        cout << "disciplina n encontrada" << endl;
}

void Historico::alterar()
{
    int achou = obterIndice();
    if ( achou > -1 )
        v[achou]->ler();
    else
        cout << "disciplina n encontrada" << endl;
}

void Historico::listarDisciplinas()
{
    cout << setprecision(2) << fixed;
    for ( int i = 0 ; i < qtd ; i++ )
        cout << v[i]->getNome() << " - " << v[i]->getCreditos()
        << " - " << v[i]->media() << endl;
}

void Historico::listarDisciplinasTipo2()
{
    cout << setprecision(2) << fixed;
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTipo() == "Tipo2" )
            cout << v[i]->getNome() << " - " << v[i]->getCreditos()
            << " - " << v[i]->media() << endl;
    }
}

void Historico::listarDisciplinasTipo3()
{
    cout << setprecision(2) << fixed;
    for ( int i = 0 ; i < qtd ; i++ )
        if ( v[i]->getTipo() == "Tipo3" && ((Tipo3*)v[i])->getNotaApresentacao() > 7.0 )
            cout << v[i]->getNome() << " - " << v[i]->getCreditos()
            << " - " << v[i]->media() << endl;
}