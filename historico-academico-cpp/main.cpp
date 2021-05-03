#include <iostream>
#include <iomanip>
#include <string>

#define MAX 20

using namespace std;

class Disciplina
{
    private:
        string nome, professor;
        int codigo, creditos, semestre, ano;
        double nota1, nota2;
    public:
        void lerCodigo( int aux ) { codigo = aux; }
        void lerDisciplina();
        void alterarDisciplina();
        void mostrar();
        string getNome()          { return nome; }
        string getProfessor()     { return professor; }
        int getCodigo()           { return codigo; }
        int getCreditos()         { return creditos; }
        int getSemestre()         { return semestre; }
        int getAno()              { return ano; }
        double getNota1()         { return nota1; }
        double getNota2()         { return nota2; }
        double getMedia()         { return (nota1+2*nota2)/3; }
};

class Disciplinas
{
    private:
        Disciplina v[MAX];
        int qtd;
    public:
        void inicializar()                           { qtd = 0; }
        Disciplina getDisciplina( int posicao )      { return v[posicao]; }
        int indice( int codigo );
        void alterar();
        void remover();
        void lerGrade();
        void mostrarGrade();
        void mostrarMedia();
        void mostrarDisciplina();
};

void Disciplina::lerDisciplina()
{
    cin.ignore();
    cout << "Entre com o nome da disciplina: ";                 getline(cin, nome);
    cout << "Entre com o valor de creditos da disciplina: ";    cin >> creditos;
    cout << "Entre com o semestre da disciplina: ";             cin >> semestre;
    cout << "Entre com o ano da disciplina: ";                  cin >> ano;
    cout << "Entre com a nota 1 e nota 2: ";                    cin >> nota1 >> nota2;
    cin.ignore();
    cout << "Entre com o nome do professor: ";                  getline(cin, professor);
    cout << "Disciplina lida com sucesso!" << endl;
}

void Disciplina::alterarDisciplina()
{
    int opcao;
    bool fim = 0;
    while (!fim)
    {
        cout << "O que deseja alterar?" << endl;
        cout << "1. Nome\n2. Creditos\n3. Semestre\n4. Ano\n5. Nota 1\n6. Nota 2\n7. Professor\n0. Sair" << endl;
        cin >> opcao;
        switch (opcao)
        {
            case 1:
                // limpartela();
                cin.ignore();
                cout << "Insira o novo nome da disciplina: ";       getline(cin, nome);
                break;
            case 2:
                // limpartela();
                cout << "Insira o novo valor dos creditos: ";       cin >> creditos;
                break;
            case 3:
                // limpartela();
                cout << "Insira o novo valor para semestre: ";      cin >> semestre;
                break;
            case 4:
                // limpartela();
                cout << "Insira o novo valor para ano: ";           cin >> ano;
                break;
            case 5:
                // limpartela();
                cout << "Insira o novo valor para Nota 1: ";        cin >> nota1;
                break;
            case 6:
                // limpartela();
                cout << "Insira o novo valor para Nota 2: ";        cin >> nota2;
                break;
            case 7:
                // limpartela();
                cin.ignore();
                cout << "Insira o novo valor para Professor: ";     getline(cin, professor);
                break;
            case 0:
                fim = 1; break;
            default:
                cout << "Opcao invalida." << endl; // pausartela();
        }
        if ( opcao != 0 ) cout << "Dado alterado com sucesso." << endl;
    }
}

void Disciplina::mostrar()
{
    cout << setprecision(2);
    cout << "Codigo: " << codigo << " Nome: " << nome << endl;
    cout << "Creditos: " << creditos << " Semestre: " << semestre << " Ano: " << ano << endl;
    cout << "Nota 1: " << nota1 << " Nota 2: " << nota2 << " Media: " << getMedia() << endl;
    cout << "Professor: " << professor << endl;
}

int Disciplinas::indice(int codigo)
{
    bool achou = 0;
    int i = 0;
    while (!achou && i < qtd)
    {
        if ( v[i].getCodigo() == codigo)
            achou = 1;
        else 
            i++;
    }
    return achou == 1 ? i : -1;
}

void Disciplinas::lerGrade()
{
    int aux;
    cout << "Entre com o codigo da disciplina: ";               cin >> aux;
    if ( indice(aux) > -1 )
    {
        cout << "Uma disciplina com este codigo ja existe no sistema." << endl;
    }
    else 
    {
        v[qtd].lerCodigo(aux);
        v[qtd].lerDisciplina();
        qtd++;
    }
}

void Disciplinas::alterar()
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser alterada: "; cin >> codigo;
    if ( indice(codigo) > -1 )
        v[indice(codigo)].alterarDisciplina();
}

void Disciplinas::remover()
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser removida: "; cin >> codigo;
    if ( indice(codigo) > -1 )
    {
        cout << "Disciplina " << v[indice(codigo)].getNome() << " removida com sucesso." << endl; 
        v[indice(codigo)] = v[qtd-1];
        qtd--; 
    }
    else
        cout << "Disciplina nao encontrada." << endl;
}

void Disciplinas::mostrarGrade()
{
    cout << endl;
    if ( qtd > 0 )
        for (int i = 0 ; i < qtd ; i++ )
        {
            v[i].mostrar();
            cout << endl;
        }
    else 
        cout << "Nenhuma disciplina foi cadastrada no Sistema.\n" << endl;    
}

void Disciplinas::mostrarMedia() 
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser consultada: "; cin >> codigo;
    if ( indice(codigo) > -1 )
    {
        cout << "Media da disciplina " << v[indice(codigo)].getNome() << ": "
        << v[indice(codigo)].getMedia() << endl;
    }
    else
        cout << "Disciplina nao encontrada." << endl;
}

void Disciplinas::mostrarDisciplina()
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser mostrada: "; cin >> codigo;
    if ( indice(codigo) > -1 )
        v[indice(codigo)].mostrar();
    else 
        cout << "Disciplina nao encontrada." << endl;
}

void menu ( Disciplinas &a )
{
    int opcao;
    bool fim = 0;
    while (!fim)
    {
        cout << "\tBem vindo ao sistema academico da FAETERJ! O que deseja fazer?\n" << endl;
        cout << "1. Adicionar uma disciplina no sistema.\n2. Conferir media de uma disciplina.\n3. Mostrar dados de uma disciplina.\n"
                "4. Remover uma disciplina.\n5. Alterar os dados de uma disciplina.\n6. Listar todas as disciplinas disponiveis no sistema.\n0. Encerrar programa." << endl;
                
        cin >> opcao;
        switch ( opcao )
        {
            case 1:
                a.lerGrade();
                break;
            case 2:
                a.mostrarMedia();
                break;
            case 3:
                a.mostrarDisciplina();
                break;
            case 4:
                a.remover();
                break;
            case 5:
                a.alterar();
                break;
            case 6:
                a.mostrarGrade();
                break;
            case 0:
                fim = 1;
                break;
            default:
                break;
        }
    }
} 

int main ()
{
    Disciplinas a;
    bool fim = 0;
    a.inicializar();
    menu(a);
    return 0;
}