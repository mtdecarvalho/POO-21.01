1 - faca um programa para gerenciar o historico escolar com no maximo 100 disciplinas
neste programa deve ser possivel realizar as seguintes operacoes

    1. inserir disciplina
    2. remover disciplina pelo codigo
    3. alterar dados da disciplina dado o codigo
    4. listar todas as disciplinas (mostrar nome, creditos e media)
    5. listar todas as disciplinas do tipo 2
    6. listar todoas as disciplinas do tipo 3 com nota da apresentacao > 7

as disciplinas podem ser dos seguintes tipos:
  tipo 1: nome, creditos, semestre, ano, nota1, nota2
          media = (nota1+nota2)/2
  tipo 2: nome, creditos, semestre, ano, nota1, nota2
          media = (nota1+2*nota2)/3
  tipo 3: nome, creditos, semestre, ano, notaMonografia, notaApresentacao, notaPratica
          media = (2*notaMonografia  + 3*notaApresentacao + notaPratica)/6