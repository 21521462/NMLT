#include <iostream>

using namespace std;

#define MAX 100

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

struct SV {
    int mssv;
    int ns;
    float dtb;
    string hoten;

    void nhap() {
        cout << "MSSV: "; cin >> mssv;
        fflush(stdin);
        cout << "Ho va ten: "; getline(cin, hoten);
        cout << "Nam sinh: "; cin >> ns;
        cout << "Diem trung binh: "; cin >> dtb;
        cout << endl;
    }

    void xuat() {
        cout << "MSSV: " << mssv << endl;
        cout << "Ho va ten: " << hoten << endl;
        cout << "Nam sinh: " << ns << endl;
        cout << "Diem trung binh: " << dtb << "\n\n";
    }
} sv[MAX];

void dtbMax(int n) {
    float M = sv[0].dtb;

    for (int i = 1; i < n; i++)
        M = max(M, sv[i].dtb);
    
    cout << "Diem trung binh lon nhat: " << M << "\n\n";
}

void dtb_duoi_5(int n, bool a) {
    if (a) {
        cout << "Danh sach sinh vien co diem trung binh nho hon 5.0:\n\n";

        for (int i = 0; i < n; i++)
            if (sv[i].dtb < 5) sv[i].xuat();
        }
    else cout << "Khong co sinh vien nao co diem trung binh nho hon 5.0.\n\n";
}

int main() {
    int n;
    bool a = false;

    cout << "Nhap so luong sinh vien: "; cin >> n;
    cout << "Nhap thong tin sinh vien:\n";
    cout << endl;

    for (int i = 0; i < n; i++)
        sv[i].nhap();

    cout << "Danh sach sinh vien:\n\n";

    for (int i = 0; i < n; i++) {
        sv[i].xuat();
        if (sv[i].dtb < 5) a = true;
    }

    dtbMax(n);
    dtb_duoi_5(n, a);

    return 0;
}