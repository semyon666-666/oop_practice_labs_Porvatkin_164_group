#include <iostream>
using namespace std;

void swapNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    cout << "vvedite pervoe chislo: ";
    cin >> num1;

    cout << "vvedite vtoroe chislo: ";
    cin >> num2;

    cout << "\n do obmena:" << endl;
    cout << "pervoe chislo: " << num1 << endl;
    cout << "vtoroe chislo: " << num2 << endl;


    swapNumbers(&num1, &num2);

    cout << "\n posle obmena:" << endl;
    cout << "pervoe chislo: " << num1 << endl;
    cout << "vtoroe chislo: " << num2 << endl;

    return 0;
}
