#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>


using namespace std;

class FormaGeometrica
{
	public:
		virtual void ler()	      {		           }
		virtual string obterNome()    { return	"FormaGeo";}
		virtual double area()	      { return 0;          }
};

class Quadrado : public FormaGeometrica
{
	private:
		double lado;
	public:
		void ler();
		double area();
		string obterNome();
};

void Quadrado::ler()
{
	cout << "Lado:";
	cin >> lado;
}
double Quadrado::area()
{
	return lado*lado;
}
string Quadrado::obterNome()
{	
	return "Quadrado";
}

class Retangulo : public FormaGeometrica
{
	private:
		double base,altura;
	public:
		void ler();
		double area();
		string obterNome();
};

void Retangulo::ler()
{
	cout << "Base:";
	cin >> base;
	cout << "Altura:";
	cin >> altura;
}

double Retangulo::area()
{
	return base*altura;
}
string Retangulo::obterNome()
{
	return "Retangulo";
}

class Circulo : public FormaGeometrica
{
	private:
		double raio;
	public:
		void ler();
		double area();
		string obterNome();
};

void Circulo::ler()
{
	cout << "Raio:";
	cin >> raio;
}
double Circulo::area()
{
       return 3.1415*raio*raio;
}
string Circulo::obterNome()
{
	return "Circulo";
}

class Elipse : public FormaGeometrica
{
	private:
		double raio1,raio2;
	public:
		void ler();
		double area();
		string obterNome();
};

void Elipse::ler()
{
	cout << "Raio1:";
	cin >> raio1;
	cout << "Raio2:";
	cin >> raio2;
}
double Elipse::area()
{
       return 3.1415*raio1*raio2;
}
string Elipse::obterNome()
{
	return "Elipse";
}

class FormasGeometricas
{
	private:
		FormaGeometrica* vet[100];
		int qtd;
	public:
		virtual ~FormasGeometricas();
		void ler();
		void listar();
};

FormasGeometricas::~FormasGeometricas()
{
	for(int i=0;i<qtd;i++)
		delete vet[i];
}

FormaGeometrica* criarFormaGeo()
{
	int tp;
	do{
		cout << "1-Quadrado" << endl << 
	   		"2-Retangulo" << endl <<
			"3-Circulo" <<  endl <<
			"4-Elipse" <<  endl <<
			"Entre com a sua escolha:";
		cin >> tp;
	}while (tp<1 || tp>4);
	switch(tp)
	{
	    case 1: return new Quadrado();
	    case 2: return new Retangulo();
	    case 3: return new Circulo();
	    case 4: return new Elipse();
	    default:  cout << "deu ruim!!!";		exit(0);
	}	
}

void FormasGeometricas::ler()
{
	cout << "Entre com a qtd:";
	cin >> qtd;
	for(int i=0; i<qtd;i++)
	{
		vet[i] = criarFormaGeo();
		vet[i]->ler();
	}
}

void FormasGeometricas::listar()
{
	for(int i=0; i<qtd;i++)
		cout << setw(20) << left << vet[i]->obterNome() << 
			setw(10) << setprecision(2) << fixed << right << vet[i]->area() << endl;
}

int main()
{
	FormasGeometricas fg;
	fg.ler();
	fg.listar();
	return 0;
}





