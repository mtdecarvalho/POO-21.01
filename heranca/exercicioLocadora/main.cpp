#include <iostream>

using namespace std;

class IAlugavel
{
    public:
        virtual void ler() = 0;
        virtual double alugel() = 0;
        virtual void mostrar() = 0;
        virtual int getCodigo() = 0;           
        virtual int getAnoDeLancamento() = 0;  
        virtual string getTipo() = 0;          
        virtual string getTitulo() = 0;        
        virtual string getEstilo() = 0;        
        virtual string getProdutora() = 0;     
        virtual string getMidia() = 0;   
        // virtual string getPlataforma() = 0;
        // virtual string getAtorPrincipal() = 0;
        // virtual string getDiretor() = 0;
};

class Item : public IAlugavel
{
    private:
        int codigo, anoDeLancamento;
        string titulo, estilo, produtora, midia;
        double aluguel;
    public:
        virtual void ler();
        virtual void mostrar();
        virtual double alugel() = 0;
        virtual int getCodigo()             { return codigo; }
        virtual int getAnoDeLancamento()    { return anoDeLancamento; }
        virtual string getTitulo()          { return titulo; }
        virtual string getEstilo()          { return estilo; }
        virtual string getProdutora()       { return produtora; }
        virtual string getMidia()           { return midia; }
};

void Item::ler()
{
    cout << "Insira o codigo: "; cin >> codigo;
    cout << "Insira o ano de lancamento: "; cin >> anoDeLancamento;
    cout << "Insira o titulo: "; cin.ignore(); getline(cin, titulo);
    cout << "Insira o estilo: "; getline(cin, estilo);
    cout << "Insira a produtora: "; getline(cin, produtora);
    cout << "Insira o tipo de midia: "; getline(cin, midia);
}

void Item::mostrar()
{
    cout << "Codigo -> " << getCodigo() << " Nome -> " << getTitulo() << endl;
    cout << "Tipo -> " << getTipo() << " Midia -> " << getMidia() << endl;
    cout << "Ano -> " << getAnoDeLancamento() << " Alugel -> " << alugel() << endl;
}

class Filme : public Item
{
    protected:
        string atorPrincipal, diretor;
    public:
        void ler();
        double alugel();
        string getTipo()                    { return "Filme"; }
        string getAtorPrincipal()           { return atorPrincipal; }
        string getDiretor()                 { return diretor;       }
};

void Filme::ler()
{
    Item::ler();
    cout << "Insira o nome do ator principal: "; getline(cin, atorPrincipal);
    cout << "Insira o nome do diretor: "; getline(cin, diretor);
}

double Filme::alugel()
{
    if ( getAnoDeLancamento() < 2020 )
        return 5.00;
    else if ( getAnoDeLancamento() >= 2020 )
        return 7.00;
}

class Jogo : public Item
{
    protected:
        int numeroDeJogadores;
        string plataforma;
    public:
        void ler();
        double alugel();
        string getTipo()                { return "Jogo"; }
        int getNumeroDeJogadores()      { return numeroDeJogadores; }
        string getPlataforma()          { return plataforma; }
};

void Jogo::ler()
{
    Item::ler();
    cout << "Insira o numero de jogadores: "; cin >> numeroDeJogadores;
    cout << "Insira a plataforma: "; cin.ignore(); getline(cin, plataforma);
}

double Jogo::alugel()
{
    if ( plataforma == "xbox series" || plataforma == "ps5" || plataforma == "nintendo switch" )
    {
        if ( getAnoDeLancamento() < 2020 )
            return 1.0 * 7.00;
        else if ( getAnoDeLancamento() >= 2020 )
            return 1.0 * 12.00;
    }
    else
    {
        if ( getAnoDeLancamento() < 2020 )
            return 0.6 * 7.00;
        else if ( getAnoDeLancamento() >= 2020 )
            return 0.6 * 12.00;
    }
}

IAlugavel* criarItem()
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

class Locadora
{
    private:
        IAlugavel* v[100];
        int qtd;
    public:
        Locadora()      { qtd = 0; }
        ~Locadora()     {}
        void inserir();
        void remover();
        void alterar();
        void listarDadaInformacao();
        void listarJogosPlataforma();
        void listarAlugel();
        int obterIndice();
};

int Locadora::obterIndice()
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
            if ( ((Filme*)v[i])->getAtorPrincipal().find(filtro) != string::npos || ((Filme*)v[i])->getDiretor().find(filtro) != string::npos )
                v[i]->mostrar();
        else if ( v[i]->getTipo() == "Jogo" )
            if ( ((Jogo*)v[i])->getPlataforma().find(filtro) != string::npos )
                v[i]->mostrar();
    }
}

void Locadora::listarJogosPlataforma()
{
    string plataforma;
    cout << "Insira a plataforma: "; cin.ignore(); getline(cin, plataforma);
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTipo() == "Jogo" )
            if ( ((Jogo*)v[i])->getPlataforma() == plataforma )
                v[i]->mostrar();
    }
}

void Locadora::listarAlugel()
{
    int codigo, posicao;
    cout << "Insira o codigo do produto a ter o alugel mostrado: "; cin >> codigo;
    posicao = obterIndice();
    if ( posicao > -1 )
        cout << "Valor de alugel -> " << v[posicao]->alugel() << endl;
    else
        cout << "Nada foi encontrado com esse codigo." << endl;
}

int menu()
{
    int op;
    cout << "Bem vindo a locadora!" << endl;
    cout << "1 - Inserir um novo item" << endl;
    cout << "2 - Remover um item dado o codigo" << endl;
    cout << "3 - Alterar dados de um item" << endl;
    cout << "4 - Listar itens dado um filtro" << endl;
    cout << "5 - Listar os jogos de uma plataforma" << endl;
    cout << "6 - Mostrar o valor do alugel dado o codigo" << endl;
    cout << "0 - Sair" << endl;
    cout << "Entre com a opcao: "; cin >> op;
    return op;
}

int main ()
{
    Locadora a;
    int op;
    do
    {
        op = menu();
        switch (op)
        {
            case 1: a.inserir(); break;
            case 2: a.remover(); break;
            case 3: a.alterar(); break;
            case 4: a.listarDadaInformacao(); break;
            case 5: a.listarJogosPlataforma(); break;
            case 6: a.listarAlugel(); break;
            case 0: break;
            default: break;
        }
    } while ( op > 0 );
    return 0;
}