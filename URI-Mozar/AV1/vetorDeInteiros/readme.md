2-) faça um programa para ler n valores inteiros e mostra-los na ordem inversa da leitura
o programa principal eh este e nao pode ser alterado

```c++
int main()
{
    TVetInt v;
    v.ler();
    v.inverter();
    v.listar();
    return 0;
}
```

entrada: na primeira linha temos o valor de n (0 < n <= 100), na segunda linha temos n numeros inteiros m (-10000 < m < 10000), separados com espaco
ex:
10
1 2 3 4 5 6 7 8 9 10
            
saida: listar os numeros, na mesma linha, na ordem inversa da leitura, separados por espaco, sendo que o ultimo numero nao pode ter espaco depois
obs: nao se esqueca de pular linha, no ultimo valor
ex: 
10 9 8 7 6 5 4 3 2 1
