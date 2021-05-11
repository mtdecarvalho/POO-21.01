#include <iostream>

using namespace std;

int main () 
{
    int linhas, colunas, tabuleiro[100][100], linha, coluna;

    while ( cin >> linhas >> colunas )
    {
        for ( linha = 0 ; linha < linhas ; linha++ )   // leitura do campo
            for ( coluna = 0 ; coluna < colunas ; coluna++ )
            {
                cin >> tabuleiro[linha][coluna];
                if ( tabuleiro[linha][coluna] == 1 ) // tem pao de queijo
                    tabuleiro[linha][coluna] = 9;
            }

        for ( linha = 0 ; linha < linhas ; linha++ ) // preenchimento
            for ( coluna = 0 ; coluna < colunas ; coluna++ )
                if ( tabuleiro[linha][coluna] == 0 )
                {
                    if ( linha < linhas-1 && tabuleiro[linha+1][coluna] == 9 ) // abaixo
                        tabuleiro[linha][coluna]++;
                    if ( linha > 0 && tabuleiro[linha-1][coluna] == 9 ) //acima
                        tabuleiro[linha][coluna]++;
                    if ( coluna < colunas-1 && tabuleiro[linha][coluna+1] == 9 ) // direita
                        tabuleiro[linha][coluna]++;
                    if ( coluna > 0 && tabuleiro[linha][coluna-1] == 9 ) // esquerda
                        tabuleiro[linha][coluna]++;
                }

        for ( linha = 0 ; linha < linhas ; linha++ ) // impressao do campo
        {
            for ( coluna = 0 ; coluna < colunas ; coluna++ )
                cout << tabuleiro[linha][coluna];
            cout << "\n";
        }
    }
    return 0;
}