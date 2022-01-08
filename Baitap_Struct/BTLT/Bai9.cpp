#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

int n = 0;

struct PS {
    int t;
    int m;
} ps[MAX];

void nhap() {
    int N;

    do {
        cout << "   Nhap so phan so muon nhap N (N > 0): "; cin >> N;
        cout << endl;
    } while (N <= 0);

    for (int i = n; i < N + n; i++) {
        do {
            cout << "   Nhap tu va mau (mau khac 0) cua phan so thu " << i + 1 << ": ";
            cin >> ps[i].t >> ps[i].m;
        } while (ps[i].m == 0);
        cout << endl;
    }
    n += N;
}

void xuat() {
    int N;

    do {
        cout << "   Nhap so phan so muon xuat N (0 < N < n): "; cin >> N;
        cout << endl;
    } while (N <= 0 || N > n);

    cout << "   Mang phan so: ";

    for (int i = 0; i < N; i++) {
        if (ps[i].m == 1 || ps[i].t == 0) cout << ps[i].t << ' ';
        else cout << ps[i].t << '/' << ps[i].m << ' ';
    }
    cout << "\n\n";
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void rutGon() {
    for (int i = 0; i < n; i++) {
        if (ps[i].t % ps[i].m == 0) {
            ps[i].t /= ps[i].m;
            ps[i].m = 1;
        }
        else {
            int u = UCLN(abs(ps[i].t), abs(ps[i].m));

            ps[i].t /= u;
            ps[i].m /= u;
        }
    }
}

void firstPositive() {
    for (int i = 0; i < n; i++)
        if (ps[i].t > 0 && ps[i].m > 0 || ps[i].t < 0 && ps[i].m < 0) {
            cout << "   Phan so duong dau tien trong mang: ";
            cout << ps[i].t << '/' << ps[i].m << endl;
            return;
        }

    cout << "   Mang khong co phan so duong." << endl;
}

void demAmDuong() {
    int am = 0, duong = 0;

    for (int i = 0; i < n; i++) {
        if (ps[i].t > 0 && ps[i].m > 0 || ps[i].t < 0 && ps[i].m < 0)
            duong++;
        if (ps[i].t < 0 && ps[i].m > 0 || ps[i].t > 0 && ps[i].m < 0)
            am++;
    }

    cout << "   Mang co " << am << " phan so am va " << duong << " phan so duong.\n\n";
}

void PS_min_max() {
    float m = ps[0].t / (float)ps[0].m;
    float M = ps[0].t / (float)ps[0].m;
    int im = 0, iM = 0;

    for (int i = 0; i < n; i++) {
        if (m > min(m, ps[i].t / (float)ps[i].m)) {
            m = min(m, ps[i].t / (float)ps[i].m);
            im = i;
        }
        if (M < max(m, ps[i].t / (float)ps[i].m)) {
            M = max(m, ps[i].t / (float)ps[i].m);
            iM = i;
        }
    }

    cout << "   Phan so nho nhat/lon nhat trong mang: ";

    if (ps[im].m == 1 || ps[im].t == 0) cout << ps[im].t << ' ';
    else cout << ps[im].t << '/' << ps[im].m << ' ';

    if (ps[iM].m == 1 || ps[iM].t == 0) cout << ps[iM].t;
    else cout << ps[iM].t << '/' << ps[iM].m;

    cout << "\n\n";
}

void PS_sort() {
    cout << "   Mang sau khi sep tang dan: ";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (ps[i].t / (float)ps[i].m > ps[j].t / (float)ps[j].m)
                swap(ps[i], ps[j]);

        if (ps[i].m == 1 || ps[i].t == 0) cout << ps[i].t << ' ';
        else cout << ps[i].t << '/' << ps[i].m << ' ';
    }

    cout << "\n\n   Mang sau khi sep giam dan: ";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (ps[i].t / (float)ps[i].m < ps[j].t / (float)ps[j].m)
                swap(ps[i], ps[j]);

        if (ps[i].m == 1 || ps[i].t == 0) cout << ps[i].t << ' ';
        else cout << ps[i].t << '/' << ps[i].m << ' ';
    }

    cout << "\n\n";
}

void pressAnyKey(char &c) {
    do {
        cout << "An phim 1 de tiep tuc, phim 0 de ket thuc: ";
        cin >> c;
    } while (c != '1' && c != '0');
}

void Selection() {
    int op;
    char c;

    cout << setw(9) << " " << "CHUONG TRINH MANG PHAN SO\n";
    cout << setfill('-');
    cout << setw(43) << "-" << endl;
    cout << "1. Nhap/xuat N phan so\n";
    cout << "2. Rut gon moi phan so\n";
    cout << "3. Dem so luong phan so am/duong trong mang\n";
    cout << "4. Tim phan so duong dau tien trong mang\n";
    cout << "5. Tim phan so nho nhat/lon nhat trong mang\n";
    cout << "6. Sap xep mang tang dan/giam dan\n";
    cout << setw(43) << "-" << endl;
    cout << setfill(' ');
    cout << "Nhap lua chon cua ban: "; cin >> op;

    switch (op) {
        case 1:
            cout << "1. Nhap/xuat N phan so\n\n";
            nhap();
            xuat();

            pressAnyKey(c);
            if (c == '1') Selection();
            else exit(0);
        case 2:
            cout << "2. Rut gon moi phan so\n\n";
            
            if (n > 0) {
                rutGon();
                cout << "   Rut gon thanh cong.\n\n";
            }
            else cout << "   Mang trong.\n\n";

            pressAnyKey(c);
            if (c == '1') Selection();
            else exit(0);
        case 3:
            cout << "3. Dem so luong phan so am/duong trong mang\n\n";
            
            if (n > 0) demAmDuong();
            else cout << "   Mang trong.\n\n";

            pressAnyKey(c);
            if (c == '1') Selection();
            else exit(0);
        case 4:
            cout << "4. Tim phan so duong dau tien trong mang\n\n";

            if (n > 0) firstPositive();
            else cout << "   Mang trong.\n\n";

            pressAnyKey(c);
            if (c == '1') Selection();
            else exit(0);
        case 5:
            cout << "5. Tim phan so nho nhat/lon nhat trong mang.\n\n";

            if (n > 0) PS_min_max();
            else cout << "   Mang trong.\n\n";

            pressAnyKey(c);
            if (c == '1') Selection();
            else exit(0);
        case 6:
            cout << "6. Sap xep mang tang dan/giam dan.\n\n";

            if (n > 0) PS_sort();
            else cout << "   Mang trong.\n\n";

            pressAnyKey(c);
            if (c == '1') Selection();
            else exit(0);
        default:
            cout << "Moi ban nhap lua chon khac.\n\n";
            Selection();
            break;
    }
}

int main() {
    Selection();

    return 0;
}