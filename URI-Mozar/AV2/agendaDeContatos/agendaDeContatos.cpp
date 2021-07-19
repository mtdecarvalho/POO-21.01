#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

class Contato
{
    private:
        string nome, email, telefone;
    public:
        void ler();
        string getNome()            { return nome;     }
        string getEmail()           { return email;    }
        string getTelefone()        { return telefone; }
};

void Contato::ler()
{
    cin.ignore();
    getline(cin, nome);
    getline(cin, email);
    getline(cin, telefone);
}

class Agenda
{
    private:
        list<Contato> lista;
        list<Contato>::iterator it;
    public:
        void inserir(Contato c);
        void remover();
        void listar();
};

void Agenda::inserir(Contato c)
{
    bool achou = 0;
    for ( auto it = lista.begin() ; it != lista.end() && !achou ; it++ )
    {
        if ( c.getEmail() == it->getEmail() )
            achou = 1;
    }
    if ( !achou )
        lista.push_back(c);
}

void Agenda::remover()
{
    string email;
    cin.ignore();
    getline(cin, email);
    for ( auto it=lista.begin() ; it != lista.end() ; it++ )
    {
        if ( it->getEmail() == email )
            it = lista.erase(it);
    }
}

void Agenda::listar()
{
    cout << "Nome                          Email                                     Telefone" << endl;
    for ( auto it=lista.begin() ; it!=lista.end() ; it++ )
    {
        cout << setw(30) << setfill(' ') << left << it->getNome()
        << setw(32) << it->getEmail() << setw(18) << right << it->getTelefone() << endl;
    }
}

int main()
{
    Agenda agenda;
    Contato c;
    int op;
    do {
        cout << "1 - inserir\n2 - remover\n3 - listar\n4 - sair\nEntre com a sua escolha:" << endl;
        cin >> op;
        switch ( op )
        {
            case 1:
                c.ler();
                agenda.inserir(c);
                break;
            case 2:
                agenda.remover();
                break;
            case 3:
                agenda.listar();
                break;
            case 4:
                cout << "Programa encerrado!" << endl;
            default:
                break;
        }
    } while (op != 4);
    return 0;
}