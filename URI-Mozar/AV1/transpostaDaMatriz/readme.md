7-) faça um programa que leia uma matriz de caracter e mostre a transposta da matriz.
o programa principal eh este e nao pode ser alterado

```C++
    int main()
    {
        TMatriz a;
	a.ler();
	a.transposta();
        a.mostrar();
        return 0;
    }
```

entrada: na primeria linha teremos dois inteiros N e M (0 < N,M <= 100) contendo a quantidade de linhas e colunas da matriz, respectivamente.
na sequencia teremos N Linhas, onde para cada linha teremos M caracteres 
ex:

    3 4
    ABCD
    xyzw
    1234

saida: mostrar a transposta da matriz lida
    Ax1
    By2
    Cz3
    Dw4