#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    int sum = 0;
    for(int i = 0; i < SIZE; i++) {
        cout << "vvedite element " << i + 1 << ": ";
        cin >> arr[i];
    }


    for(int i = 0; i < SIZE; i++) {
        if(arr[i] > 0) {
            sum += arr[i];
        }
    }


    cout << "summa pologitelnyx elementov: " << sum << endl;

    return 0;
}
