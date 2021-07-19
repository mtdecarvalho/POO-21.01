#include <iostream>
#include <iomanip>

using namespace std;

class ICliente
{
    public:
        virtual void ler() = 0;
        virtual void calculoIR() = 0;
        virtual void mostrar() = 0;
        virtual int getCodigo() = 0;
        virtual string getNome() = 0;
        virtual double getRendaAnual() = 0;
        virtual double getIR() = 0;
        virtual char getTipo() = 0;
};

class Cliente : public ICliente
{
    private:
        int codigo;
        string nome;
        double rendaAnual;
    public:
        virtual void ler();
        virtual void mostrar();
        virtual void calculoIR() = 0;
        virtual double getIR() = 0;
        char getTipo()              { return 'C';           }
        int getCodigo()             { return codigo;        }
        string getNome()            { return nome;          }
        double getRendaAnual()      { return rendaAnual;    }
};

void Cliente::ler()
{
    cin >> codigo;
    cin.ignore(); getline(cin, nome);
    cin >> rendaAnual;
}

void Cliente::mostrar()
{
    cout << "Codigo      : " << getCodigo() << endl;
    cout << "Nome        : " << getNome() << endl;
    cout << "Renda Anual : " << setprecision(2) << fixed << getRendaAnual() << endl;
}

class PessoaJuridica : public Cliente
{
    private:
        int inscricaoMunicipal, inscricaoEstadual;
        string CNPJ;
        double IR;
    public:
        void ler();
        void mostrar();
        void calculoIR();
        double getIR()                      { return IR;                    }
        char getTipo()                      { return 'J';                   }
        string getCNPJ()                    { return CNPJ;                  }
        int getInscricaoMunicipal()         { return inscricaoMunicipal;    }
        int getInscricaoEstadual()          { return inscricaoEstadual;     }
};

void PessoaJuridica::calculoIR()
{
    if ( getRendaAnual() > 200000 )  IR = 0.25 * getRendaAnual();
    else IR = 0.15 * getRendaAnual();
}

void PessoaJuridica::ler()
{
    Cliente::ler();
    cin.ignore(); getline(cin, CNPJ);
    cin >> inscricaoMunicipal >> inscricaoEstadual;
    calculoIR();
}

void PessoaJuridica::mostrar()
{
    Cliente::mostrar();
    cout << "CNPJ        : " <<  getCNPJ() << endl;
    cout << "Inscr. Mun. : " <<  getInscricaoMunicipal() << endl;
    cout << "Inscr. Est. : " <<  getInscricaoEstadual() << endl;
}

class PessoaFisica : public Cliente 
{
    private:
        int dependentes;
        string CPF, profissao;
        double IR;
    public:
        void ler();
        void mostrar();
        void calculoIR()                { IR = 0.07 * getRendaAnual();  }
        double getIR()                  { return IR;                    }
        char getTipo()                  { return 'F';                   }
        string getCPF()                 { return CPF;                   }
        string getProfissao()           { return profissao;             }
        int getDependentes()            { return dependentes;           }
};

void PessoaFisica::ler()
{
    Cliente::ler();
    cin.ignore(); getline(cin, CPF);
    getline(cin, profissao);
    cin >> dependentes;
    calculoIR();
}

void PessoaFisica::mostrar()
{
    Cliente::mostrar();
    cout << "CPF         : " << getCPF() << endl;
    cout << "Profissao   : " << getProfissao() << endl;
    cout << "Dependentes : " << getDependentes() << endl;
}

class Clientes
{
    private:
        ICliente* v[100];
        int qtd;
    public:
        Clientes()                      { qtd = 0; }
        ~Clientes();
        void inserirPessoaFisica();
        void inserirPessoaJuridica();
        void remover(int codigo);
        int obterIndice(int codigo);
        void visualizarPessoa(int codigo);
        void consultarIR(int codigo);
        void listar();
};

Clientes::~Clientes()
{
    for ( int i = 0 ; i < qtd ; i++ )
        delete v[i]; 
}

int Clientes::obterIndice(int codigo)
{
    int i = 0;
    bool achou = 0;
    while ( !achou && i < qtd )
    {
        if ( v[i]->getCodigo() == codigo )
            achou = 1;
        else
            i++;
    }
    return achou ? i : -1;
}

void Clientes::inserirPessoaFisica()
{
    v[qtd] = new PessoaFisica();
    v[qtd]->ler();
    qtd++;
}

void Clientes::inserirPessoaJuridica()
{
    v[qtd] = new PessoaJuridica();
    v[qtd]->ler();
    qtd++;
}

void Clientes::remover(int codigo)
{
    int pos = obterIndice(codigo);
    if ( pos > -1 )
    {
        v[pos] = v[qtd-1];
        qtd--;
    }
}

void Clientes::visualizarPessoa(int codigo)
{
    int pos = obterIndice(codigo);
    if ( pos > -1 )
    {
        v[pos]->mostrar();
    }
}

void Clientes::consultarIR(int codigo)
{
    int pos = obterIndice(codigo);
    if ( pos > -1 )
    {
        cout << "R$" << setw(10) << setfill(' ') << right << v[pos]->getIR() << endl;
    }
}

void Clientes::listar()
{
    cout << "Codigo Nome                           F/J             CPF/CNPJ           IR" << endl;
    for ( int i = 0 ; i < qtd ; i++ )
    {
        cout << setw(5) << setfill('0') << right << v[i]->getCodigo() << " " << setw(32) << setfill(' ') << left << v[i]->getNome()
        << v[i]->getTipo();
        switch( v[i]->getTipo() )
        {
            case 'F':
                cout << setw(22) << setfill(' ') << right << ((PessoaFisica*)v[i])->getCPF();
                break;
            case 'J':
                cout << setw(22) << setfill(' ') << right << ((PessoaJuridica*)v[i])->getCNPJ();
                break;
        }
        cout << " R$ " << setw(9) << setfill(' ') << right << setprecision(2) << fixed << v[i]->getIR() << endl;
    }
}

int main ()
{ 
    Clientes c;
    int opcao, codigo;
    do 
    {
        cout << "1 - inserir pessoa fisica\n2 - inserir pessoa juridica\n3 - remover\n4 - consultar\n5 - ir\n6 - listar\n7 - sair\nEntre com a sua escolha:" << endl;
        cin >> opcao;
        switch (opcao)
        {
            case 1:
                c.inserirPessoaFisica();
                break;
            case 2:
                c.inserirPessoaJuridica();
                break;
            case 3:
                cin >> codigo;
                c.remover(codigo);
                break;
            case 4:
                cin >> codigo;
                c.visualizarPessoa(codigo);
                break;
            case 5:
                cin >> codigo;
                c.consultarIR(codigo);
                break;
            case 6:
                c.listar();
                break;
            case 7:
                cout << "Programa encerrado!" << endl;
                break;
        }
    } while( opcao != 7 );
    return 0;
}