#include <iostream>

using namespace std;

#define MAX 100

bool b = false;

void Nhap_Xuat(float *&p, int &n) {
    cout << "Nhap so phan tu day so huu ti: "; cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "p[" << i << "] = ";
        cin >> p[i];

        if (p[i] < 1) b = true;
    }

    cout << endl << "Day so vua nhap: ";

    for (int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << "\n\n";
}

void Xuat_nho_hon1(float *p, int n) {
    if (b) {
        cout << "Cac so nho hon 1: ";

        for (int i = 0; i < n; i++)
            if (p[i] < 1) cout << p[i] << " ";

        cout << "\n\n";
    }
    else cout << "Day khong co so nao nho hon 1.\n\n";
}

void Tong(float *p, int n) {
    float S = 0;

    for (int i = 0; i < n; i++) S += p[i];

    cout << "Tong cua day so: " << S << "\n\n";
}

void Tich(float *p, int n) {
    float S = 1;

    for (int i = 0; i < n; i++) S *= p[i];

    cout << "Tich cua day so: " << S << "\n\n";
}

int main() {
    int n;
    float *p = new float[MAX];

    Nhap_Xuat(p, n);
    Xuat_nho_hon1(p, n);
    Tong(p, n);
    Tich(p, n);

    delete[] p;

    return 0;
}