#include <iostream>

using namespace std;

#define MAX 100

void saoChep(int *a, int *&b) {
    for (int i = 0; i < 10; i++)
        b[i] = a[i];

    cout << "Mang B vua sao chep: ";

    for (int i = 0; i < 10; i++)
        cout << b[i] << ' ';

    cout << endl;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *a = arr;
    int *b = new int[MAX];

    saoChep(a, b);
    delete[] b;
    return 0;
}