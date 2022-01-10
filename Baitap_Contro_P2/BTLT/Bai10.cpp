#include <iostream>

using namespace std;

int *mangDao(int a[], int n) {
    int *pa = new int[n];

    for (int i = 0; i < n; i++)
        pa[i] = a[n - 1 - i];

    return pa;
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pa = mangDao(a, 10);

    cout << "Mang a: ";

    for (int i = 0; i < 10; i++)
        cout << a[i] << ' ';

    cout << endl;
    cout << "Mang dao cua a: ";

    for (int i = 0; i < 10; i++)
        cout << pa[i] << ' ';

    cout << endl;

    delete[] mangDao(a, 10);
    return 0;
}