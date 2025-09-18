#include <iostream>

using namespace std;

int main()
{
    cout << "vvedite chislo: ";
    int a;
    cin >> a;
    if(a % 2 == 0) {
        cout << "vvedennoe chislo "<< a << " chetnoe";
    } else {
        cout << "vvedennoe chislo "<< a << " nechetnoe";
    }
    return 0;
}
