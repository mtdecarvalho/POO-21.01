#include "IAlugavel.h"
#include "Locadora.h"

#include <iomanip>

Locadora::Locadora()
{
    qtd = 0;
}

Locadora::~Locadora()
{
    for (int i = 0 ; i < qtd ; i++ )
        delete v[i];
}

int Locadora::obterIndice()
{
    int codigo, i = 0;
    bool achou = 0;
    cout << "Insira o codigo do item: "; cin >> codigo;
    while ( !achou && i < qtd )
    {
        if ( v[i]->getCodigo() == codigo )
            achou = 1;
        else
            i++;
    }
    return achou ? i : -1;
}

Item* criarItem()
{
    int tipo;
    do
    {
        cout << "Selecione o tipo de item:" << endl;
        cout << "1 - Filme" << endl;
        cout << "2 - Jogo" << endl;
        cout << "Entre com a escolha: ";
        cin >> tipo;
    } while ( tipo < 1 || tipo > 2 );
    switch (tipo)
    {
    case 1:
        return new Filme();
    case 2:
        return new Jogo();
    default:
        cout << "Deu ruim"; exit(0);
    }
}

void Locadora::inserir()
{
    v[qtd] = criarItem();
    v[qtd]->ler();
    qtd++;
}

void Locadora::remover()
{
    int pos = obterIndice();
    if ( pos > -1 )
    {
        v[pos] = v[qtd-1];
        qtd--;
    }
    else
    {
        cout << "Nenhum item com esse codigo foi encontrado." << endl;
    }
}

void Locadora::alterar()
{
    int pos = obterIndice();
    if ( pos > -1 )
        v[pos]->ler();
    else 
        cout << "Nenhum item com esse codigo foi encontrado." << endl;
}

void Locadora::listarDadaInformacao()
{
    string filtro;
    cout << "Insira o filtro: "; cin.ignore(); getline(cin, filtro);
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTitulo().find(filtro) != string::npos || v[i]->getProdutora().find(filtro) != string::npos ||
            v[i]->getMidia().find(filtro) != string::npos || v[i]->getEstilo().find(filtro) != string::npos)
                v[i]->mostrar();
        else if ( v[i]->getTipo() == "Filme" )
        {
            if ( ((Filme*)v[i])->getAtorPrincipal().find(filtro) != string::npos || ((Filme*)v[i])->getDiretor().find(filtro) != string::npos )
                v[i]->mostrar();
        }
        else if ( v[i]->getTipo() == "Jogo" )
        {
            if ( ((Jogo*)v[i])->getPlataforma().find(filtro) != string::npos )
                v[i]->mostrar();
        }
    }
}

void Locadora::listarJogosPlataforma()
{
    int cont = 0;
    string plataforma;
    cout << "Insira a plataforma: "; cin.ignore(); getline(cin, plataforma);
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTipo() == "Jogo" )
            if ( ((Jogo*)v[i])->getPlataforma() == plataforma )
            {
                cont++;
                v[i]->mostrar();
            }
    }
    if ( cont == 0 ) cout << "Nenhum jogo foi encontrado para esta plataforma." << endl;
}

void Locadora::listarAlugel()
{
    int posicao;
    posicao = obterIndice();
    if ( posicao > -1 )
    {
        cout << setprecision(2) << fixed;
        cout << "Valor de alugel -> " << v[posicao]->alugel() << endl;
    }
    else
        cout << "Nada foi encontrado com esse codigo." << endl;
}