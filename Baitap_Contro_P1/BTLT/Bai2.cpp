#include <iostream>

using namespace std;

int main() {
    int *p = new int[5], k, n;

    do {
        k = 0;

        do {
            cout << "Nhap n (n > 0) co k chu so (0 < k <= 5): ";
            cin >> n;
        } while (n < 0);

        while (n > 0) {
            *(p + k) = n % 10;
            n /= 10;
            k++;
        }
    } while (k <= 0 || k > 5);

    cout << "Ket qua sau khi sap xep: ";

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++)
            if (*(p + i) > *(p + j)) swap(*(p + i), *(p + j));

        cout << *(p + i);
    }

    delete[] p;
}