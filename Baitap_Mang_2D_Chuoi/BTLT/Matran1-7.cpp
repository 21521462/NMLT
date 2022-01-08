#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define MAX 100

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

void nhapMang(int &r, int &c) {
    do {
        cout << "Nhập số dòng (dòng > 0): "; cin >> r;
        cout << "   Nhập số cột (cột > 0): "; cin >> c;
    } while (r <= 0 || c <= 0);
}

void xuatMang(int a[][MAX], int r, int c) {
    srand((int)time(0));

    cout << "Chuỗi:\n";

    for (int i = 0; i < r; i++) {
        cout << "   ";

        for (int j = 0; j < c; j++) {
            a[i][j] = randInt(-9, 9);
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

int Bai1(int a[][MAX], int &r, int &c) {
    cout << "1. ";
    nhapMang(r, c);
    cout << "   ";
    xuatMang(a, r, c);

    cout << endl;
    return 0;
}

int Bai2(int a[][MAX], int r, int c) {
    int f, m = 0;
    
    cout << "2. ";
    xuatMang(a, r, c);
    cout << "   Nhập phần tử muốn tìm kiếm: "; cin >> f;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == f) {
                cout << "   Vị trí phần tử được tìm thấy: ";
                cout << '(' << i << ',' << j << ")\n";
                m++;
            }
        }
    }

    if (m == 0) cout << "   Không tìm thấy.\n";

    cout << endl;
    return 0;
}

int Bai3() {
    int a[MAX][MAX], ra, ca;

    do {
        cout << "3. Nhập số dòng (dòng > 0): "; cin >> ra;
        cout << "   Nhập số cột (cột > 0): "; cin >> ca;
    } while (ra <= 0 || ca <= 0);

    if (ra == ca) {
        if (ra == 1) {
            cout << "   Mảng đối xứng.\n\n";
            return 0;
        }

        cout << "   Nhập mảng:\n";

        for (int i = 0; i < ra; i++) {
            for (int j = 0; j < ca; j++) {
                cout << "   a[" << i << "][" << j << "] = ";
                cin >> a[i][j];
            }
        }

        cout << "   Mảng:\n";

        for (int i = 0; i < ra; i++) {
            cout << "   ";

            for (int j = 0; j < ca; j++)
                cout << a[i][j] << " ";

            cout << endl;
        }

        for (int i = 0; i < ra; i++) {
            for (int j = i + 1; j < ca; j++) {
                if (a[i][j] != a[j][i]) {
                    cout << "   Mảng không đối xứng.\n\n";
                    return 0;
                }
            }
        }
        
        cout << "   Mảng đối xứng.\n\n";
    }
    else cout << "   Mảng không có đường chéo chính.\n\n";

    return 0;
}

int Bai4(int a[][MAX], int r, int c) {
    cout << "4. ";
    nhapMang(r, c);
    cout << "   ";
    xuatMang(a, r, c);

    int S = 0;

    cout << "   Tổng các phần tử trên dòng:\n";
    for (int i = 0; i < r; i++) {
        int s = 0;

        for (int j = 0; j < c; j++) 
            s += a[i][j];

        S += s;
        cout << "   Dòng " << i << ": " << s << endl;
    }

    cout << "   Tổng các phần tử trên cột:\n";
    for (int j = 0; j < c; j++) {
        int s = 0;

        for (int i = 0; i < r; i++)
            s += a[i][j];

        cout << "   Cột " << j << ": " << s << endl;
    }

    cout << "   Tổng các phần tử trên toàn mảng: " << S << endl;

    if (r == c) {
        int St = 0, Sd = 0;
        S = 0;

        for (int i = 0; i < r; i++)
            S += a[i][i];

        cout << "   Tổng các phần tử trên đường chéo chính: " << S << endl;

        for (int i = 0; i < r; i++) {
            for (int j = i + 1; j < c; j++) {
                St += a[i][j];
                Sd += a[j][i];
            }
        }

        cout << "   Tổng các phần tử trên nửa trên: " << S + St << endl;
        cout << "   Tổng các phần tử trên nữa dưới: " << S + Sd << "\n\n";
    }
    else cout << "   Mảng không có đường chéo chính.\n\n";
    return 0;
}

int Bai5(int a[][MAX], int r, int c) {
    cout << "5. ";
    nhapMang(r, c);
    cout << "   ";
    xuatMang(a, r, c);

    int M = a[0][0], m = a[0][0];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            M = max(M, a[i][j]);
            m = min(m, a[i][j]);
        }
    }

    cout << "   Giá trị nhỏ nhất, lớn nhất của mảng: " << m << ", " << M << "\n\n";
    return 0;
}

int dinhThuc(int a[][MAX], int r) {
    int s, S = 0;

    if (r == 1) return a[0][0];

    if (r == 2) return a[0][0] * a[1][1] - a[1][0] * a[0][1];

    for (int k = 0; k < r; k++) {
        int m[MAX][MAX];

        for (int i = 1; i < r; i++)
            for (int j = 0; j < r; j++) {
                if (j > k) m[i - 1][j - 1] = a[i][j];
                else if (j < k) m[i - 1][j] = a[i][j]; 
            }

        if (k % 2 == 0) s = 1;
        else s = -1;

        S += a[0][k] * s * dinhThuc(m, r - 1);
    }
    return S;
}

int Bai6(int a[][MAX], int r, int c) {
    cout << "6. ";
    nhapMang(r, c);
    
    if (r == c) {
        cout << "   ";
        xuatMang(a, r, c);
        cout << "   Định thức của ma trận: " << dinhThuc(a, r) <<"\n\n";
    }
    else cout << "   Lỗi kích thước.\n\n";

    return 0;
}

int Bai7(int a[][MAX], int r, int c) {
    cout << "7. ";
    nhapMang(r, c);
    
    if (r == c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << "   ";
                cout << "a[" << i << "][" << j << "] = ";
                cin >> a[i][j];

                if (i == j && a[i][j] != 1 || i != j && a[i][j] != 0) {
                    cout << "   Không phải ma trận đơn vị.\n\n";
                    return 0;
                }
            }
        }

        cout << "   Đây làm ma trận đơn vị.\n\n";
    }
    else cout << "   Không phải ma trận đơn vị.\n\n";

    return 0;
}

int main() {
    int a[MAX][MAX], ra, ca;

    cout << setw(26) << " " << "MA TRẬN\n";
    cout << setfill('-');
    cout << setw(60) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "1. Nhập mảng, xuất mảng\n";
    cout << "2. Tìm kiếm một phần tử trong mảng\n";
    cout << "3. Kiểm tra mảng có đối xứng qua đường chéo chính hay không?\n";
    cout << "4. Tính tổng các phần tử trên dòng/cột/toàn mảng/đường chéo\n   chính/nửa trên/nửa dưới\n";
    cout << "5. Tìm giá trị nhỏ nhất, lớn nhất của mảng\n";
    cout << "6. Tính định thức ma trận\n";
    cout <<"7. Kiểm tra ma trận có phải ma trận đơn vị hay không?\n";
    cout << setw(60) << "-" << endl;

    Bai1(a, ra, ca);
    Bai2(a, ra, ca);
    Bai3();
    Bai4(a, ra, ca);
    Bai5(a, ra, ca);
    Bai6(a, ra, ca);
    Bai7(a, ra, ca);

    return 0;
}