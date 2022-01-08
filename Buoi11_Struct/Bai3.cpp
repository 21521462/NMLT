#include <iostream>

using namespace std;

#define MAX 100

struct Tinh {
    int ma;
    int ds;
    int dt;
    string ten;

    void nhap() {
        cout << "Ma tinh: "; cin >> ma;
        fflush(stdin);
        cout << "Ten tinh: "; getline(cin, ten);
        cout << "Dan so: "; cin >> ds;
        cout << "Dien tich: "; cin >> dt;
        cout << endl;
    }

    void xuat() {
        cout << "Ma tinh: " << ma << endl;
        cout << "Ten tinh: " << ten << endl;
        cout << "Dan so: " << ds << endl;
        cout << "Dien tich: " << dt << endl;
    }
} tinh[MAX];

int main() {
    int n;
    int dtmax = 0, imax;
    bool b = false;
    
    cout << "Nhap so luong tinh: "; cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
        tinh[i].nhap();

    cout << "Danh sach tinh vua nhap:\n\n";

    for (int i = 0; i < n; i++) {
        tinh[i].xuat();
        cout << endl;
    }

    cout << "Cac tinh co dan so lon hon 1 trieu:\n\n";

    for (int i = 0; i < n; i++) {
        if (tinh[i].ds > 1000000) {
            tinh[i].xuat();
            cout << endl;
            b = true;
        }
        if (dtmax < tinh[i].dt) imax = i;
    }

    if (!b) cout << "Khong co tinh nao co dan so lon hon 1 trieu.\n\n";

    cout << "Tinh co dien tich lon nhat:\n\n";
    tinh[imax].xuat();
    cout << endl;

    return 0;
}