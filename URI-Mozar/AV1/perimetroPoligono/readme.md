1-) Faça um programa para ler os vertices de um poligono e mostrar o perimetro do poligono lido.

o programa principal eh este e nao pode ser alterado:
```c++
int main()
{
    TPoligono p;
    p.ler();
    cout << "perimetro - " << p.perimetro();
    return 0;
}
```

obs: entrada, na primeira linha teremos um inteiro n, contentendo a quantiade de vertices
    nas n linhas seguintes teremos cada vertices (ponto 2D: x,y reais), cada linha de vertices tem
    dois valores reais separados por espaco.

ex:
```
4
1.0 1.0
1.0 0.0  
0.0 0.0
0.0 1.0
```

saida deve-se escrever "perimetro - " seguido do valor do perimetro com 2 casas decimais.
ex: perimetro - 4.00        