#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int C;
    string input;
    double tempo;
    cin >> C;
    while ( C > 0 )
    {
        cin >> input;
        tempo = input.length(); tempo /= 100;
        cout << setprecision(2) << fixed;
        cout << tempo << endl;
        C--;
    }
    return 0;
}