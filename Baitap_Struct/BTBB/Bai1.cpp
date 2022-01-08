#include <iostream>
#include <cmath>

using namespace std;

struct DThuc {
    int a;
    int n;

    void nhapDT() {
        cin >> a >> n;
    }

    void xuatDT() {
        if (a != 0) {
            if (n == 1) cout << a << 'x';
            else if (n == 0) cout << a;
            else cout << a << "x^" << n;
        }
        else cout << a;
    }

    int tinhGT(int x) {
        return a * pow(x, n);
    }

    void tinhDH() {
        if (a != 0) {
            if (n == 2) cout << a * n << 'x';
            else if (n == 1) cout << a;
            else if (n == 0) cout << 0;
            else cout << a * n << "x^" << n - 1;
        }
        else cout << a;
    }
} dt1, dt2;

void Tong() {
    cout << "Don thuc 1 + don thuc 2 = ";

    if (dt1.n < dt2.n) {
        if (dt1.a == 0) dt2.xuatDT();
        else if (dt2.a == 0) dt1.xuatDT();
        else {
            dt2.xuatDT(); cout << " + ";
            dt1.xuatDT();
        }
    }
    else if (dt1.n == dt2.n) {
        int a = dt1.a + dt2.a;

        if (a != 0) {
            if (dt1.n == 0) cout << a;
            else if (dt1.n == 1) cout << a << 'x';
            else cout << a << "x^" << dt1.n;
        }
        else cout << a;
    }
    else {
        if (dt1.a == 0) dt2.xuatDT();
        else if (dt2.a == 0) dt1.xuatDT();
        else {
            dt1.xuatDT(); cout << " + ";
            dt2.xuatDT();
        }
    }
}

void Hieu() {
    cout << "Don thuc 1 - Don thuc 2 = ";

    if (dt1.n < dt2.n) {
        if (dt1.a == 0) {
            cout << "- ";
            dt2.xuatDT();
        }
        else if (dt2.a == 0) dt1.xuatDT();
        else {
            cout << "- "; dt2.xuatDT();
            cout << " + "; dt1.xuatDT();
        }
        
    }
    else if (dt1.n == dt2.n) {
        int a = dt1.a - dt2.a;

        if (a != 0) {
            if (dt1.n == 0) cout << a;
            else if (dt1.n == 1) cout << a << 'x';
            else cout << a << "x^" << dt1.n;
        }
        else cout << a;
    }
    else {
        if (dt1.a == 0) {
            cout << "- ";
            dt2.xuatDT();
        }
        else if (dt2.a == 0) dt1.xuatDT();
        else {
            dt1.xuatDT(); cout << " - ";
            dt2.xuatDT();
        }
    }
}

void Tich() {
    int a = dt1.a * dt2.a;
    int n = dt1.n + dt2.n;

    cout << "Don thuc 1 * don thuc 2 = ";

    if (a != 0) {
        if (n == 0) cout << a;
        else if (n == 1) cout << a << 'x';
        else cout << a << "x^" << n;
    }
    else cout << a;
}

void Thuong() {
    if (dt2.a != 0) {
        float a = dt1.a / (float)dt2.a;
        int n = dt1.n - dt2.n;

        cout << "Don thuc 1 / don thuc 2 = ";

        if (a != 0) {
            if (n == 0) cout << a;
            else if (n == 1) cout << a << 'x';
            else cout << a << "x^" << n;
        }
        else cout << a;
    }
    else cout << "Khong chia duoc.";
}

int main() {
    cout << "Nhap he so va so bac cua don thuc 1: "; dt1.nhapDT();
    cout << "Don thuc 1: "; dt1.xuatDT();
    cout << "\n\n";
    cout << "Nhap he so va so bac cua don thuc 2: "; dt2.nhapDT();
    cout << "Don thuc 2: "; dt2.xuatDT();
    cout << "\n\n";

    Tong();
    cout << endl;
    Hieu();
    cout << endl;
    Tich();
    cout << endl;
    Thuong();
    cout << "\n\n";

    int x;
    cout << "Nhap x: "; cin >> x;
    cout << "Gia tri cua don thuc 1 tai x = " << x << ": " << dt1.tinhGT(x) << endl;
    cout << "Gia tri cua don thuc 2 tai x = " << x << ": " << dt2.tinhGT(x) << "\n\n";

    cout << "Dao ham cua don thuc 1: "; dt1.tinhDH();
    cout << endl;
    cout << "Dao ham cua don thuc 2: "; dt2.tinhDH();
    cout << "\n\n";

    return 0;
}