#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

int randInt(int min, int max) {

    return min + rand() % (max + 1 - min);
}

int nhapMang(int &r, int &c) {

    do {
        cout << "Nhập số dòng (dòng > 0): "; cin >> r;
        cout << "   Nhập số cột (cột > 0): "; cin >> c;
    } while (r <= 0 || c <= 0);
    
    return 0;
}

int xuatMang(int a[][MAX], int r, int c) {

    srand((int)time(0));

    cout << "Mảng:\n";

    for (int i = 0; i < r; i++) {
        cout << "   ";

        for (int j = 0; j < c; j++) {
            a[i][j] = randInt(-9, 9);
            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}

int Bai1(int a[][MAX], int &ra, int &ca, int b[][MAX], int &rb, int &cb) {
    
    cout << "1. Nhập mảng A:\n   ";
    nhapMang(ra, ca);
    cout << "   ";
    xuatMang(a, ra, ca);

    cout << "   Nhập mảng B:\n   ";
    nhapMang(rb, cb);
    cout << "   ";
    xuatMang(b, rb, cb);

    if (ra != rb || ca != cb)
        cout << "   Hai mảng không cùng kích thước.\n";
    else {
        cout << "   Tổng A + B:\n";

        for (int i = 0; i < ra; i++) {
            cout << "   ";

            for (int j = 0; j < ca; j++) {
                cout << a[i][j] + b[i][j] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}

int phanTu_ij(int a[][MAX], int b[][MAX], int r, int c, int m) {

    int S = 0;

    for (int i = 0; i < m; i++) {
        S += a[r][i] * b[i][c];
    }

    return S;
}

int Bai2(int a[][MAX], int ra, int ca, int b[][MAX], int rb, int cb) {

    cout << "2.\n";

    if (ca == rb) {
        cout << "   Tích AB:\n";

        for (int i = 0; i < ra; i++) {
            cout << "   ";

            for (int j = 0; j < cb; j++) {
                cout << phanTu_ij(a, b, i, j, ca) << " ";
            }

            cout << endl;
        }

        cout << endl;
    }
    if (cb == ra) {
        cout << "   Tích BA:\n";

        for (int i = 0; i < rb; i++) {
            cout << "   ";

            for (int j = 0; j < ca; j++) {
                cout << phanTu_ij(b, a, i, j, cb) << " ";
            }

            cout << endl;
        }
    }
    if (ca != rb && cb != ra)
        cout << "   Không nhân được.\n";

    cout << endl;
    return 0;
}

int Bai3(int a[][MAX], int r, int c) {

    int S = 0, m;

    cout << "3. ";
    xuatMang(a, r, c);

    for (int i = 0; i < r; i++) {
        m = a[i][0];

        for (int j = 1; j < c; j++)
            m = max(m, a[i][j]);
        
        S += m;
    }

    cout << "   Tổng các giá trị lớn nhất trên mỗi dòng: " << S << "\n\n";
    return 0;
}

int main() {

    int a[MAX][MAX], ra, ca;
    int b[MAX][MAX], rb, cb;

    cout << setw(20) << " " << "MA TRẬN\n";
    cout << setfill('-');
    cout << setw(47) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "1. Cộng hai ma trận\n";
    cout << "2. Nhân hai ma trận\n";
    cout << "3. Tính tổng các giá trị lớn nhất trên mỗi dòng\n";
    cout << setw(47) << "-" << endl;
    
    Bai1(a, ra, ca, b, rb, cb);
    Bai2(a, ra, ca, b, rb, cb);
    Bai3(a, ra, ca);

    return 0;
}