#include <iostream>

using namespace std;

void Nhap(float *&p) {
    cout << "Nhap day so:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "p[" << i << "] = ";
        cin >> p[i];
    }

    cout << endl;
}

void Xuat(float *p) {
    for (int i = 0; i < 10; i++)
        cout << p[i] << ' ';
    
    cout << "\n\n";
}

void sapXep(float *&p) {
    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
            if (p[i] > p[j]) swap(p[i], p[j]);
}

int main() {
    float *p = new float[10];

    Nhap(p);
    cout << "Truoc khi sap xep: ";
    Xuat(p);
    sapXep(p);
    cout << "Sau khi sap xep: ";
    Xuat(p);

    delete[] p;

    return 0;
}