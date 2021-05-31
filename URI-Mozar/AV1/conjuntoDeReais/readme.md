3-) faça uma classe para representar um conjuntos de numeros reais de no maximo 100 elementos
nesta classe deve-se ter as seguintes operacoes

a. inserir elemento
b. remover elemento
c. pertence (se um elemento pertence ou nao ao conjunto)
d. esta contido (se um conjunto esta contido no outro)
e. uniao
f. interseca
g. subtracao de conjuntos

o programa principal eh este e nao pode ser alterado

```c++
int main()
{
    TConjunto a,b,c,d,e;
    int x;
    a.ler();
    b.ler();
    c.uniao(a,b);
    cout << " a UNIAO b = ";
    c.mostrar();
    d.intersecao(a,b);
    cout << " a INTERSECAO b = ";
    d.mostrar();
    cout << "d esta contido em a:" << d.estacontido(a)?"sim":"nao" << endl;
    cout << "a contem d:" << a.contem(d)?"sim"?"nao" << endl;
    cout << "c esta contido em a:" << c.estacontido(a) << endl;
    cout << "c contem a:" << c.contem(a)?"sim":"nao" << endl;
    cout << "c contem b:" << c.contem(b)?"sim":"nao" << endl;
    cout << "a contem b:" << a.contem(b)?"sim":"nao" << endl;
    cout << "a esta contido em b:" << a.estacontido(b)?"sim":"nao" << endl;
    cout << " a - b = ";
    e.subtracao(a,b);
    e.mostrar();
    cin >> x;
    while (x>0){
        cout << x << " pertence ao conjunto A: " << a.pertence(x)?"sim":"nao" << endl;
            cin >> x;
    }
    return 0;
}
```

entrada: na primeira linha termos um inteiro NA (0 < NA < 100) que representa o numero de linhas dos elementos
a serem inseridos no conjunto A (nao eh a quantidade de elementos, uma vez que podem ter elementos repetidos na entrada e no conjunto nao pode ter)
na linha seguinte teremos NA numeros inteiros separados por espaco, que devem ser inseridos no conjunto A
na seguencia teremos um inteiro NB (0 < NB < 100) que representa o numero de linhas dos elementos a serem inseridos no conjunto B (nao eh a quantidade de elementos, uma vez que podem ter elementos repetidos na entrada e no conjunto nao pode ter) 
na linha seguinte teremos NB numeros inteiros separados por espaco, que devem ser inseridos no conjunto B
na ultima linha teremos varios valores inteiros que devem ser lidos e testados se pertencem ou nao ao conjunto A,
este linha termina com o numero 0, que nao deve ser testado.
      ex: 10
          1 2 3 3 2 1 2 7 8 8
          5
          1 2 3 4 5
    	  1 2 3 4 5 6 7 8 9 10 11 0	
