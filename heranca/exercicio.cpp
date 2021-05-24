#include <iostream>

using namespace std;

class Disciplina
{
    private:
        string nome;
        int codigo, creditos, semestre, ano;
        double nota1, nota2;
    public:
        double getNota1()                       { return nota1;         }
        double getNota2()                       { return nota2;         }
        virtual void ler();
        virtual void calcularMedia()            {                       }
        virtual string getTipo()                { return "Tipo";        }
        virtual int getCodigo()                 { return codigo;        }
        virtual string getNome()                { return nome;          }   
        virtual int getCreditos()               { return creditos;      }
        virtual double getMedia()               { return 0;             }
        virtual double getNotaApresentacao()    { return 0;             }
};

void Disciplina::ler()
{
    cout << "Codigo -> "; cin >> codigo;
    cout << "Nome -> "; cin.ignore(); getline(cin, nome);
    cout << "Creditos -> "; cin >> codigo;
    cout << "Semestre -> "; cin >> semestre;
    cout << "Ano -> "; cin >> ano;
    cout << "Nota 1 -> "; cin >> nota1;
    cout << "Nota 2 -> "; cin >> nota2;
}

class Tipo1 : public Disciplina 
{
    private:
        double media;
    public:
        void calcularMedia()     { media = (getNota1()+getNota2())/2;   }
        double getMedia()        { return media;                        }
        string getTipo()         { return "Tipo1";                      }
};

class Tipo2 : public Disciplina
{
    private:
        double media;
    public:
        void calcularMedia()     { media = (getNota1()+2*getNota2())/3;     }
        double getMedia()        { return media;                            }
        string getTipo()         { return "Tipo2";                          }
};

class Tipo3 : public Disciplina
{
    private:
        string nome;
        int codigo, creditos, semestre, ano;
        double notaMonografia, notaApresentacao, notaPratica, media;
    public:
        void ler() ;
        void calcularMedia()                 { media = (2*notaMonografia  + 3*notaApresentacao + notaPratica)/6; }
        string getTipo()                     { return "Tipo3";                                                   }
        int getCodigo()                      { return codigo;                                                    }
        string getNome()                     { return nome;                                                      }
        int getCreditos()                    { return creditos;                                                  }
        double getMedia()                    { return media;                                                     }
        double getNotaApresentacao()         { return notaApresentacao;                                          }
};

void Tipo3::ler()
{
    cout << "Codigo -> "; cin >> codigo;
    cout << "Nome -> "; cin.ignore(); getline(cin, nome);
    cout << "Creditos -> "; cin >> codigo;
    cout << "Semestre -> "; cin >> semestre;
    cout << "Ano -> "; cin >> ano;
    cout << "Nota da Monografia -> "; cin >> notaMonografia;
    cout << "Nota da Apresentacao -> "; cin >> notaApresentacao;
    cout << "Nota Pratica -> "; cin >> notaPratica;
}

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

class Historico
{
    private:
        Disciplina* v[100];
        int qtd;
    public:
        Historico() { qtd = 0; }
        virtual ~Historico();
        int obterIndice();
        void inserir();
        void remover();
        void alterar();
        void listarDisciplinas();
        void listarDisciplinasTipo2();
        void listarDisciplinasTipo3();
};

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
    v[qtd]->calcularMedia();
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
    for ( int i = 0 ; i < qtd ; i++ )
    {

        cout << v[i]->getNome() << " - " << v[i]->getCreditos()
        << " - " << v[i]->getMedia() << " - " << v[i]->getTipo() << endl;
    }
}

void Historico::listarDisciplinasTipo2()
{
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTipo() == "Tipo2" )
            cout << v[i]->getNome() << " - " << v[i]->getCreditos()
            << " - " << v[i]->getMedia() << endl;
    }
}

void Historico::listarDisciplinasTipo3()
{
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTipo() == "Tipo3" && v[i]->getNotaApresentacao() > 7.0 )
            cout << v[i]->getNome() << " - " << v[i]->getCreditos()
            << " - " << v[i]->getMedia() << endl;
    }
}

int menu()
{
    int opcao;
    cout << "Bem vindo ao Sistema Academico" << endl
    << "1. Inserir disciplina" << endl
    << "2. Remover disciplina" << endl
    << "3. Alterar disciplina" << endl
    << "4. Listar todas as disciplinas" << endl 
    << "5. Listar todas as disciplinas de tipo 2" << endl
    << "6. Listar todas as disciplinas de tipo 3 com nota de apresentacao maior que 7" << endl
    << "Entre com sua opcao: ";
    cin >> opcao;
    return opcao;
}

int main ()
{
    Historico a;
    int opcao;
    do {
        opcao = menu();
        switch ( opcao )
        {
            case 1: a.inserir(); break;
            case 2: a.remover(); break;
            case 3: a.alterar(); break;
            case 4: a.listarDisciplinas(); break;
            case 5: a.listarDisciplinasTipo2(); break;
            case 6: a.listarDisciplinasTipo3(); break;
            default: break;
        }
    } while ( opcao > 0 );
    return 0;
}