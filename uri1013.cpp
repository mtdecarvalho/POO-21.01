#include <iostream>

using namespace std;

int main () {
    int a, b, c, maiorab;
    cin >> a >> b >> c;
    maiorab = (a + b + abs(a-b)) / 2;
    if ( maiorab > c ) {
        cout << maiorab << " eh o maior" << endl;
    } else {
        cout << c << " eh o maior" << endl;
    }
    return 0;
}