#include <iostream>

using namespace std;

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

int BCNN(int a, int b) {
    return a * b / UCLN(a, b);
}

typedef struct PhanSo {
    int t;
    int m;
} PS;

void nhap(PS &ps) {
    cin >> ps.t >> ps.m;
    while (ps.m == 0) {
        cout << "Nhap mau so khac 0: ";
        cin >> ps.m;
    };
    cout << endl;
    
    /*do {
        ps.t = randInt(-10, 10);
        ps.m = randInt(-10, 10);
    } while (ps.m == 0);*/
}

void xuat(PS ps) {
    if (ps.m == 1) cout << ps.t << "\n\n";
    else cout << ps.t << '/' << ps.m << "\n\n";
}

void rutGon(PS &ps) {
    if (abs(ps.t) % abs(ps.m) == 0) {
        ps.t /= ps.m;
        ps.m = 1;
    }
    else {
        int u = UCLN(abs(ps.t), abs(ps.m));

        if (ps.t < 0 && ps.m < 0 || ps.t > 0 && ps.m < 0) {
            ps.t /= -u;
            ps.m /= -u;
        }
        else {
            ps.t /= u;
            ps.m /= u;
        }
    }
}

void Tong(PS ps1, PS ps2) {
    PS ps3 = {
        ps1.t * ps2.m + ps2.t * ps1.m,
        ps1.m * ps2.m
    };

    rutGon(ps3);
    xuat(ps3);
}

void Hieu(PS ps1, PS ps2) {
    PS ps3 = {
        ps1.t * ps2.m - ps2.t * ps1.m,
        ps1.m * ps2.m
    };

    rutGon(ps3);
    xuat(ps3);
}

void Tich(PS ps1, PS ps2) {
    PS ps3 = {
        ps1.t * ps2.t,
        ps1.m * ps2.m
    };

    rutGon(ps3);
    xuat(ps3);
}

void Thuong(PS ps1, PS ps2) {
    PS ps3 = {
        ps1.t * ps2.m,
        ps1.m * ps2.t
    };

    rutGon(ps3);
    xuat(ps3);
}

void kiemTra_toiGian(PS ps) {
    if (UCLN(abs(ps.t), abs(ps.m)) == 1 && abs(ps.m) != 1)
        cout << "Phan so toi gian.\n\n";
    else cout << "Phan so chua toi gian.\n\n";
}

void quyDong(PS &ps1, PS &ps2) {
    ps1.t *= BCNN(abs(ps1.m), abs(ps2.m)) / ps1.m;
    ps1.m = BCNN(abs(ps1.m), abs(ps2.m));

    ps2.t *= BCNN(abs(ps1.m), abs(ps2.m)) / ps2.m;
    ps2.m = BCNN(abs(ps1.m), abs(ps2.m));
}

void soSanh(PS ps1, PS ps2) {
    quyDong(ps1, ps2);

    if (ps1.t > ps2.t)
        cout << "Phan so 1 lon hon phan so 2.\n\n";
    else if (ps1.t == ps2.t)
        cout << "Phan so 1 bang phan so 2.\n\n";
    else
        cout << "Phan so 1 be hon phan so 2.\n\n";
}

void kiemTraAmDuong(PS ps) {
    rutGon(ps);

    if (ps.t < 0) cout << "Phan so am.\n\n";
    else if (ps.t == 0) cout << "Phan so khong am khong duong.\n\n";
    else cout << "Phan so duong.\n\n";
}

int main() {
    PhanSo ps1, ps2, ps3;
    //srand((int)time(0));
    cout << "Nhap tu va mau cua phan so 1: ";
    nhap(ps1);
    cout << "Nhap tu va mau cua phan so 2: ";
    nhap(ps2);

    cout << "Phan so 1: ";
    rutGon(ps1);
    xuat(ps1);
    cout << "Phan so 2: ";
    rutGon(ps2);
    xuat(ps2);

    soSanh(ps1, ps2);

    quyDong(ps1, ps2);
    cout << "Sau khi quy dong:\n\n";
    cout << "Phan so 1: ";
    xuat(ps1);
    cout << "Phan so 2: ";
    xuat(ps2);

    cout << "Phan so 1 + Phan so 2 = ";
    Tong(ps1, ps2);
    cout << "Phan so 1 - phan so 2 = ";
    Hieu(ps1, ps2);
    cout << "Phan so 1 * phan so 2 = ";
    Tich(ps1, ps2);
    cout << "Phan so 1 / phan so 2 = ";
    Thuong(ps1, ps2);

    cout << "Nhap tu va mau cua phan so 3: ";
    nhap(ps3);
    /*cout << "Phan so 3: ";
    xuat(ps3);*/
    kiemTra_toiGian(ps3);
    kiemTraAmDuong(ps3);

    return 0;
}