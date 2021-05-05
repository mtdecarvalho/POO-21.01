#include "classes.h"
// #include "util.h"

#include <iostream>
#include <iomanip>

void Disciplina::lerCodigo( int aux ) { codigo = aux; }
string Disciplina::getNome()          { return nome; }
int Disciplina::getCodigo()           { return codigo; }
double Disciplina::getMedia()         { return (nota1+2*nota2)/3; }

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
    cout << "\nDisciplina lida com sucesso!\n" << endl;
    pausartela();
}

void Disciplina::alterarDisciplina()
{
    int opcao;
    bool fim = 0;
    while (!fim)
    {
        limpartela();
        cout << "------------- FAETERJ PETROPOLIS -------------" << endl;
        cout << "O que deseja alterar?" << endl;
        cout << "1. Nome\n2. Creditos\n3. Semestre\n4. Ano\n5. Nota 1\n6. Nota 2\n7. Professor\n0. Sair" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> opcao;
        switch (opcao)
        {
            case 1:
                cin.ignore();
                cout << "Insira o novo nome da disciplina: ";       getline(cin, nome);
                break;
            case 2:
                cout << "Insira o novo valor dos creditos: ";       cin >> creditos;
                break;
            case 3:
                cout << "Insira o novo valor para semestre: ";      cin >> semestre;
                break;
            case 4:
                cout << "Insira o novo valor para ano: ";           cin >> ano;
                break;
            case 5:
                cout << "Insira o novo valor para Nota 1: ";        cin >> nota1;
                break;
            case 6:
                cout << "Insira o novo valor para Nota 2: ";        cin >> nota2;
                break;
            case 7:
                cin.ignore();
                cout << "Insira o novo valor para Professor: ";     getline(cin, professor);
                break;
            case 0:
                fim = 1; break;
            default:
                cout << "Opcao invalida." << endl; pausartela();
        }
        if ( opcao != 0 ) 
        {
            cout << "Dado alterado com sucesso." << endl;
            pausartela();
        }
    }
}

void Disciplina::mostrar()
{
    cout << setprecision(2);
    cout << "------------- DISCIPLINA " << codigo << " -------------" << endl;
    cout << "\n";
    cout << "Codigo: " << codigo << " Nome: " << nome << endl;
    cout << "Creditos: " << creditos << " Semestre: " << semestre << " Ano: " << ano << endl;
    cout << "Nota 1: " << nota1 << " Nota 2: " << nota2 << " Media: " << getMedia() << endl;
    cout << "Professor: " << professor << endl;
    cout << "\n";
    cout << "\t\t--------" << endl;

}

void Historico::inicializar()                           { qtd = 0; }
Disciplina Historico::getDisciplina( int posicao )      { return v[posicao]; }

int Historico::indice(int codigo)
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

void Historico::lerGrade()
{
    int aux;
    cout << "------------- FAETERJ PETROPOLIS -------------" << endl;
    cout << "\n";
    cout << "Entre com o codigo da disciplina: ";               cin >> aux;
    if ( indice(aux) > -1 )
    {
        cout << "Uma disciplina com este codigo ja existe no sistema." << endl;
        pausartela();
    }
    else 
    {
        v[qtd].lerCodigo(aux);
        v[qtd].lerDisciplina();
        qtd++;
    }
}

void Historico::alterar()
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser alterada: "; cin >> codigo;
    if ( indice(codigo) > -1 )
        v[indice(codigo)].alterarDisciplina();
}

void Historico::remover()
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser removida: "; cin >> codigo;
    if ( indice(codigo) > -1 )
    {
        cout << "\nDisciplina " << v[indice(codigo)].getNome() << " removida com sucesso.\n" << endl; 
        v[indice(codigo)] = v[qtd-1];
        qtd--; 
        pausartela();
    }
    else
    {
        cout << "Disciplina nao encontrada." << endl;
        pausartela();
    }
}

void Historico::mostrarGrade()
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
    pausartela();
}

void Historico::mostrarMedia() 
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser consultada: "; cin >> codigo;
    if ( indice(codigo) > -1 )
    {
        cout << "\n";
        cout << "Media da disciplina " << v[indice(codigo)].getNome() << ": "
        << v[indice(codigo)].getMedia() << endl;
        cout << "\n";
    }
    else
        cout << "Disciplina nao encontrada.\n" << endl;
    pausartela();
}

void Historico::mostrarDisciplina()
{
    int codigo;
    cout << "Insira o codigo da disciplina a ser mostrada: "; cin >> codigo;
    if ( indice(codigo) > -1 )
        v[indice(codigo)].mostrar();
    else 
    {
        cout << "Disciplina nao encontrada." << endl;
        pausartela();
    }
}