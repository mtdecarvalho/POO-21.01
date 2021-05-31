5-) faça um programa para controlar as notas da turma de poo, o programa deve ler o nome, nota1 e nota 2, dos alunos (no maximo 100)
e depois listar todos os alunos, mostrando o nome, nota1, nota2, media e situacao (aprovado ou reprovado)

media = (nota1 + 2*nota2)/3
se media>=6 entao aprovado senao reprovado

```C++
int main()
{
    TTurma t;
    t.ler();
    t.listar();
    return 0;
}
```

entrada: na primeira linha temos um inteiro N (0 < N < 100), seguida de 3*N linhas, onde contendo o nome, nota1 e nota2
ex entrada:
2
Jo A Kim
7.0
10.0
Jo utro mundo
7.0
1.0

saida: listar o nome alinhamdo a esquerda com 50 colunas, seguido da media com 6 colunas e 2 casas decimais de precisao, seguido da situacao Aprovado ou Reprovado
Jo A Kim                                            9.00 Aprovado
Jo utro mundo                                       3.00 Reprovado