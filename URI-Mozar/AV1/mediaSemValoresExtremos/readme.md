6-) faça um programa que leia n numeros reais (no maximo 100)
e mostre a media sem os valores extremos (maior e menor valor)
ex: 1 7 5 1 3 5 7 3
maior = 7
menor = 1
media sem extremos = (5 + 3 + 5 + 3)/4 = 16/4 = 4

```C++
    int main()
    {
        TVet v;
        v.ler();
        cout << fixed << setprecision(2);
        cout << "Maior: "<< v.maior() << endl;
        cout << "Menor: "<< v.menor() << endl;
        cout << "Media sem extremos: "<< v.mediaEx() << endl;
        return 0;
    }
```

entrada:
Contém na primeira linha um número n inteiro (0 < N <= 100) e na segunda linha teremos N números reais, separados por espaço.
ex:
10
1.0 2.0 8.0 1.0 5.0 6.0 7.0 1.0 7.0 3.0

saida:
Deve contém 3 linhas 

"Maior:" seguido do maior valor com 2 casas decimais de precisão

"Menor:" seguido do menor valor com 2 casas decimais de precisão

"Media sem extremos:" seguido do valor da media com 2 casas decimais de precisão 

Maior: 8.00
Menor: 1.00
Media sem extremos: 5.00