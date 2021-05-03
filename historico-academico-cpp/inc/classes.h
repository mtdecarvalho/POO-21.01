#ifndef _CLASSES_H_
#define _CLASSES_H_

#include <string>
#include "util.h"

#define MAX 20

using namespace std;

class Disciplina
{
    private:
        string nome, professor;
        int codigo, creditos, semestre, ano;
        double nota1, nota2;
    public:
        void lerCodigo( int aux );
        void lerDisciplina();
        void alterarDisciplina();
        void mostrar();
        string getNome();  
        string getProfessor();
        int getCodigo();
        int getCreditos();
        int getSemestre();
        int getAno();
        double getNota1();
        double getNota2();
        double getMedia();
};

class Historico
{
    private:
        Disciplina v[MAX];
        int qtd;
    public:
        void inicializar();
        Disciplina getDisciplina( int posicao );
        int indice( int codigo );
        void alterar();
        void remover();
        void lerGrade();
        void mostrarGrade();
        void mostrarMedia();
        void mostrarDisciplina();
};

#endif