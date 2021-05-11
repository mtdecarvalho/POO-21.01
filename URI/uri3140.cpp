#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string html, input;
    getline(cin, html);
    
    while (html.find("<html>") != string::npos )
    {
        getline(cin, input);
        if ( input.find("</html>") != string::npos ) html = input; // se achar html, enviar para o inicio e fechar o loop
        if ( input.find("<body>") != string::npos ) // achou body, pulou a tag e entrou no conteudo
        {
            getline(cin, input);
            while ( input.find("</body>") == string::npos ) // enquanto nao achar o fim de body, imprimir tudo
            {
                cout << input << endl;
                getline(cin, input);
            }
        }
    }

    return 0;
}