4-) faça um programa para ler um polinomio de no maximo 100 termos, ler o valor de x e mostrar 
o valor do polinomio para o valor de x lido.

polinomio = c1*x^e1 + c2*x^e2 + .... cn*x^en

onde ci - coeficiente do i-esimo termo do polinomio
ei - expoente do i-esimo termo do polinomio

```c++
int main()
    {
        TPolinomio p;
        float x;
        p.ler();
        cin >> x;
        cout << fixed << setprecision(2);
        cout << "p(" << x << ") = " << p.calcular(x) << endl;
        return 0;
    }
```
entrada: na primeira linha temos N inteiro (0 < N < 100), seguido de n linhas com um numero real C e um inteiro E, que 
representam o Coefidiente e Expoente do termo lido. e por final teremos um unico numero real, que é o Valor de X
para o qual deve calcular o valor do polinomio

4
1.5 2
-3.1 1
4.0 0
2.1 10        
0.0

polinomio:  1.5X^2 -3.1X^1 + 4.0X^0 + 2.1X^10   
            1.5*0 -3.1*0 + 4.0*1 + 2.1*0 = 4.00 
saida: p(0.0) = 4.0 
