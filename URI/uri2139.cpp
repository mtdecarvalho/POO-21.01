#include <iostream>

using namespace std;

int main ()
{
    int mes, dia, faltam;
    while ( cin >> mes >> dia )
    {
        switch ( mes ) 
        {
            case 1:
                faltam = 360 - dia; break;
            case 2:
                faltam = 329 - dia; break;
            case 3:
                faltam = 300 - dia; break;
            case 4:
                faltam = 269 - dia; break;
            case 5:
                faltam = 239 - dia; break;
            case 6:
                faltam = 208 - dia; break;
            case 7:
                faltam = 178 - dia; break;
            case 8:
                faltam = 147 - dia; break;
            case 9:
                faltam = 116 - dia; break;
            case 10:
                faltam = 86 - dia; break;
            case 11:
                faltam = 55 - dia; break;
            case 12:
                if ( dia < 24 ) cout << "Faltam " << dia - 25 << " dias para o natal!" << endl;
                else if ( dia == 24 ) cout << "E vespera de natal!" << endl;
                else if ( dia == 25 ) cout << "E natal!" << endl;
                else if ( dia > 25 ) cout << "Ja passou!" << endl;
                break;
        }
        if ( mes != 12 ) cout << "Faltam " << faltam << " dias para o natal!" << endl;
    }
    return 0;
}