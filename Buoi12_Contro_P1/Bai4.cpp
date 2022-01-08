#include <iostream>

using namespace std;

#define MAX 100

void nhapA(float *p_A, int &n) {
    cout << "Nhap so phan tu day A: "; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "*(p_A + " << i << ") = ";
        cin >> *(p_A + i);
    }
}

void capPhatB(float *p_A, int n) {
    float *p_B = new float [MAX];

    for (int i = 0; i < n; i++) {
        *(p_B + i) = *(p_A + i);
    }

    delete[] p_A;

    for (int i = 0; i < n; i++) {
        cout << *(p_B + i) << " ";
    }

    delete[] p_B;
}

int main() {
    int n;
    float *p_A = new float[MAX];

    nhapA(p_A, n);
    cout << "Day B sao chep tu day A: ";
    capPhatB(p_A, n);

    return 0;
}