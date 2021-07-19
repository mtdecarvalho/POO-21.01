#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

class Lanche
{
    private:
        int codigo;
        double preco;
        string nome;
    public:
        void ler();
        void setPreco(double valor)     { preco = valor; }
        int getCodigo()                 { return codigo; }
        string getNome()                { return nome;   }
        double getPreco()               { return preco;  }
};

void Lanche::ler()
{
    cin >> codigo;
    cin.ignore(); getline(cin, nome);
    cin >> preco;
}

class Cardapio
{
    private:
        list<Lanche> cardapio;
    public:
        void inserir(Lanche l);
        void remover(int codigo);
        void consultarPreco(int codigo);
        void atualizarPreco(int codigo, double preco);
        void listar();
        list<Lanche>::iterator obterIndice(int codigo);
};

void Cardapio::inserir(Lanche l)
{
    bool achou = 0;
    for ( auto it = cardapio.begin() ; it != cardapio.end() && !achou ; it++ )
    {
        if ( l.getCodigo() == it->getCodigo() )
            achou = 1;
    }
    if ( cardapio.size() < 20 && !achou )
    {
        cardapio.push_back(l);
    }
}

void Cardapio::remover(int codigo)
{
    bool achou = 0;
    for ( auto it=cardapio.begin() ; it!=cardapio.end() && !achou ; it++ )
    {
        if ( it->getCodigo() == codigo )
        {
            it = cardapio.erase(it);
            achou = 1;
        }
    }
}

void Cardapio::consultarPreco(int codigo)
{
    bool achou = 0;

    for ( auto it=cardapio.begin() ; it != cardapio.end() && !achou ; it++ )
    {
        if ( it->getCodigo() == codigo )
        {
            cout << "R$" << setw(5) << setfill(' ') << right << it->getPreco() << endl;
            achou = 1;
        }
    }
    if ( !achou )
        cout << "R$" << setw(5) << setfill(' ') << right << "0.00" << endl;
}

void Cardapio::atualizarPreco(int codigo, double preco)
{
    bool achou = 0;

    for ( auto it = cardapio.begin() ; it != cardapio.end() && !achou ; it++ )
    {
        if ( it->getCodigo() == codigo )
        {
            it->setPreco(preco);
            achou = 1;
        }
    }
}

void Cardapio::listar()
{
    cout << "Codigo Nome                             Preco" << endl;
    for ( auto it = cardapio.begin() ; it != cardapio.end() ; it++ )
    {
        cout << setw(5) << setfill('0') << right << it->getCodigo() << "  "
        << setw(30) << setfill(' ') << left << it->getNome() <<
        "R$" << setw(6) << setfill(' ') << right << setprecision(2) << fixed << it->getPreco() << endl;
    }
}

int main()
{
    Cardapio cardapio;
    Lanche l;
    int op, codigo;
    double preco;
    do
    {
        cout << "1 - inserir\n2 - remover\n3 - consultar\n4 - alterar\n5 - listar\n6 - sair\nEntre com a sua escolha:" << endl;
        cin >> op;
        switch (op)
        {
            case 1:
                l.ler();
                cardapio.inserir(l);
                break;
            case 2:
                cin >> codigo;
                cardapio.remover(codigo);
                break;
            case 3:
                cin >> codigo;
                cardapio.consultarPreco(codigo);
                break;
            case 4:
                cin >> codigo >> preco;
                cardapio.atualizarPreco(codigo, preco);
                break;
            case 5:
                cardapio.listar();
                break;
            case 6:
                cout << "Programa encerrado!" << endl;
                break;
            default:
                break;
        }
    } while (op != 6);
    return 0;
}