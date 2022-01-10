#include <iostream>

using namespace std;

int *banSao(int a[], int n) {
    int *pa = new int[n];

    for (int i = 0; i < n; i++)
        pa[i] = a[i];
    
    return pa;
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pa = banSao(a, 10);
    
    cout << "Mang a: ";

    for (int i = 0; i < 10; i++)
        cout << a[i] << ' ';
    
    cout << endl;
    cout << "Ban sao cua mang a: ";

    for (int i = 0; i < 10; i++)
        cout << pa[i] << ' ';

    cout << endl;

    delete[] banSao(a, 10);
    return 0;
}