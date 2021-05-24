#include <iostream>

using namespace std;

class Disciplina
{
    
    public:
        virtual void ler()              {                       }
        virtual void calcularMedia()    {                       }
        virtual void alterar()          {                       }
        virtual string getTipo()        { return "Tipo";        }
        virtual int getCodigo()         { return 0;             }
        virtual string getNome()        { return "Disciplina";  }
        virtual int getCreditos()       { return 0;             }
        virtual double getMedia()       { return 0;             }
        virtual double getNota()        { return 0;             }
};

class Tipo1 : public Disciplina 
{
    private:
        string nome;
        int codigo, creditos, semestre, ano;
        double nota1, nota2, media;
    public:
        void ler();
        void calcularMedia()    { media = (nota1+nota2)/2;  }
        string getTipo()        { return "Tipo1";           }
        int getCodigo()         { return codigo;            }
        string getNome()        { return nome;              }
        int getCreditos()       { return creditos;          }
        double getMedia()       { return media;             }
};

void Tipo1::ler()
{
    cin >> codigo; cin.ignore();
    getline(cin, nome);
    cin >> creditos >> semestre >> ano >> nota1 >> nota2;
    calcularMedia();
}

class Tipo2 : public Disciplina
{
    private:
        string nome;
        int codigo, creditos, semestre, ano;
        double nota1, nota2, media;
    public:
        void ler();
        void calcularMedia()    { media = (nota1+2*nota2)/3;    }
        string getTipo()        { return "Tipo2";               }
        int getCodigo()         { return codigo;                }
        string getNome()        { return nome;                  }
        int getCreditos()       { return creditos;              }
        double getMedia()       { return media;                 }
};

void Tipo2::ler()
{
    cin >> codigo; cin.ignore();
    getline(cin, nome);
    cin >> creditos >> semestre >> ano >> nota1 >> nota2;
    calcularMedia();
}

class Tipo3 : public Disciplina
{
    private:
        string nome;
        int codigo, creditos, semestre, ano;
        double notaMonografia, notaApresentacao, notaPratica, media;
    public:
        void ler();
        void calcularMedia()    { media = (2*notaMonografia  + 3*notaApresentacao + notaPratica)/6; }
        string getTipo()        { return "Tipo3";                                                   }
        int getCodigo()         { return codigo;                                                    }
        string getNome()        { return nome;                                                      }
        int getCreditos()       { return creditos;                                                  }
        double getMedia()       { return media;                                                     }
        double getNota()        { return notaApresentacao;                                          }
};

void Tipo3::ler()
{
    cin >> codigo; cin.ignore();
    getline(cin, nome);
    cin >> creditos >> semestre >> ano >> notaMonografia >> notaApresentacao >> notaPratica;
    calcularMedia();
}

Disciplina* criarDisciplina()
{
    int tp;
    do
    {
        cout << "1 - Tipo 1" << endl <<
                "2 - Tipo 2" << endl <<
                "3 - Tipo 3" << endl <<
                "Entre com a escolha: ";
        cin >> tp;
    } while ( tp < 1 || tp > 3);
    switch (tp)
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

        cout << v[i]->getNome() << " " << v[i]->getCreditos()
        << " " << v[i]->getMedia() << " " << v[i]->getTipo() << endl;
    }
}

void Historico::listarDisciplinasTipo2()
{
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTipo() == "Tipo2" )
            cout << v[i]->getNome() << " " << v[i]->getCreditos()
            << " " << v[i]->getMedia() << endl;
    }
}

void Historico::listarDisciplinasTipo3()
{
    for ( int i = 0 ; i < qtd ; i++ )
    {
        if ( v[i]->getTipo() == "Tipo3" && v[i]->getNota() > 7.0 )
            cout << v[i]->getNome() << " " << v[i]->getCreditos()
            << " " << v[i]->getMedia() << endl;
    }
}

int menu()
{
    int opcao;
    cout << "bem vindo ao sistema academico" << endl
    << "1. inserir disciplina" << endl
    << "2. remover disciplina" << endl
    << "3. alterar disciplina" << endl
    << "4. listar todas as disciplinas" << endl 
    << "5. listar todas as disciplinas de tipo 2" << endl
    << "6. listar todas as disciplinas de tipo 3 com nota de apresentacao maior que 7" << endl
    << "entre com sua opcao: ";
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