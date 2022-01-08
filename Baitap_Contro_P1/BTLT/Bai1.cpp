#include <iostream>

using namespace std;

#define MAX 100

int main() {
    int a[MAX], n;
    int *p = a;

    cout << "Nhap so phan tu cua mang: "; cin >> n;
    cout << endl << "Nhap mang:\n";

    for (int i = 0; i < n; i++) {
        cout << "*(p + " << i << ") = ";
        cin >> *(p + i);
    }

    cout << endl << "Mang vua nhap: ";

    for (int i = 0; i < n; i++)
        cout << *(p + i) << " ";

    cout << "\n\n" << "Mang sau khi sap xep: ";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (*(p + i) > *(p + j)) swap(*(p + i), *(p + j));

        cout << *(p + i) << " ";
    }

    cout << endl;
}