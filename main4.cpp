#include <iostream>
using namespace std;

int findMax(int* arr, int size) {

    if (size <= 0) {
        cout << "oshibka: massiv pust" << endl;
        return -1;
    }


    int* ptr = arr;

    int max = *ptr;


    for (int i = 1; i < size; i++) {

        ptr++;

        if (*ptr > max) {
            max = *ptr;
        }
    }
    return max;
}

int main() {

    int arr[] = {6, 3, 2, 9, 4, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);


    int maxElement = findMax(arr, size);


    cout << "max element massiva: " << maxElement << endl;

    return 0;
}



