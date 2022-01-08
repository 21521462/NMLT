#include <iostream>

using namespace std;

#define MAX 100

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void nhap(int *p, int &n) {
    do {
        cout << "Nhap so phan tu cho mang so nguyen (n > 0): ";
        cin >> n;
    } while (n <= 0);

    cout << endl << "   Nhap mang:\n";

    for (int i = 0; i < n; i++) {
        cout << "   *(p + " << i << ") = ";
        cin >> *(p + i);
    }
    cout << endl;
}

void xuat(int *p, int n) {
    cout << "   Mang vua nhap: ";

    for (int i = 0; i < n; i++)
        cout << *(p + i) << " ";
    cout << "\n\n";
}

void Bai1(int *p, int n) {
    bool e = false;

    cout << "1. ";
    nhap(p, n);
    xuat(p, n);

    for (int i = 0; i < n; i++)
        if (isPrime(*(p + i))) {
            e = true;
            break;
        }

    if (e) {
        cout << "   Cac so nguyen to co trong mang: ";
        for (int i = 0; i < n; i++)
            if (isPrime(*(p + i))) cout << *(p + i) << " ";

        cout << "\n\n";
    }
    else cout << "   Mang khong co so nguyen to.\n\n";
}

void Bai2(int *p, int n) {
    bool dx = true;

    cout << "2. ";
    nhap(p, n);
    xuat(p, n);

    for (int i =  0; i < n / 2; i++)
        if (*(p + i) != *(p + (n - 1 - i))) {
            dx = false;
            break;
        }
    if (dx) cout << "   Mang doi xung.\n\n";
    else cout << "   Mang khong doi xung.\n\n";
}

int xoaK(int *p, int &n) {
    int k;

    cout << "   Nhap chi so k can xoa: "; cin >> k;

    if (k < 0 || k >= n) return 0;
    else {

        for (int i = k; i < n; i++)
            *(p + i) = *(p + i + 1);
        n--;
        
        return 1;
    }
}

void Bai3(int *p, int n) {
    cout << "3. ";
    nhap(p, n);
    xuat(p, n);

    int i = xoaK(p, n);

    if (i == 0) cout << "   " << i << "\n\n";
    else {
        cout << "   " << i << endl;
        cout << "   Mang sau khi xoa: ";

        for (int i = 0; i < n; i++)
            cout << *(p + i) << " ";

        cout << "\n\n";
    }
}

void Bai4(int *p, int n) {
    int pM = *p, iM = 0;

    cout << "4. ";
    nhap(p, n);
    xuat(p, n);

    for (int i = 1; i < n; i++)
        if (pM < max(pM, *(p + i))) {
            pM = *(p + i);
            iM = i;
        }

    cout << "   Vi tri phan tu lon nhat mang: " << iM << "\n\n";
}

bool isExistNegative(int *p, int n, int &k) {
    for (int i = 0; i < n; i++)
        if (*(p + i) < 0) {
            k = i;
            return true;
        }
    return false;
}

void Bai5(int *p, int n) {
    int k;

    cout << "5. ";
    nhap(p, n);
    xuat(p, n);

    if (isExistNegative(p, n, k)) {
        for (int i = k; i < n && *(p + i) < 0; i++) {
            if (*(p + k) < *(p + i)) k = i;
        }

        cout << "   Vi tri phan tu am lon nhat: " << k << "\n\n";
    }
    else cout << "   Mang khong co phan tu am.\n\n";
}

int main() {
    int *p = new int[MAX];
    int n;

    Bai1(p, n);
    Bai2(p, n);
    Bai3(p, n);
    Bai4(p, n);
    Bai5(p, n);

    delete[] p;
}