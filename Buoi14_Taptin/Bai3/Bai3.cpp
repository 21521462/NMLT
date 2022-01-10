#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define MAX 100

struct SV {
    string ten;
    int id;
    int ns;
    float dtb;
} sv[MAX];

int n = 0;

void Nhap();
void ghiFile();
void docFile();
void Selection(int op);
void TimKiemTheoMa();
void xoaDS();

int main() {
    int op;

    cout << setw(7) << " " << "DANH SACH SINH VIEN\n";
    cout << setfill('-');
    cout << setw(34) << "-" << endl;
    cout << "1. Ghi them sinh vien\n";
    cout << "2. Doc va xuat danh sach sinh vien\n";
    cout << "3. Tim kiem sinh vien theo ma\n";
    cout << "4. Xoa danh sach\n";
    cout << setw(34) << "-" << endl;
    cout << setfill(' ');
    cout << "Nhap lua chon cua ban: "; cin >> op;

    Selection(op);
}

char pressAnyKey(char c) {
    do {
        cout << "Nhap 1 de tiep tuc, 0 de ket thuc: ";
        cin >> c;
        cout << endl;
    } while (c != '1' && c != '0');

    return c;
}

void Selection(int op) {
    char c;

    switch (op) {
        case 1:
            ghiFile();
            n++;
        
            if (pressAnyKey(c) == '1') main();
            else exit(0);
        case 2:
            docFile();

            if (pressAnyKey(c) == '1') main();
            else exit(0);
        case 3:
            if (n == 0) {
                cout << "Danh sach trong.\n\n";

                if (pressAnyKey(c) == '1') main();
                else exit(0);
            }
            else {
                TimKiemTheoMa();

                if (pressAnyKey(c) == '1') main();
                else exit(0);
            }
        case 4:
            xoaDS();
            cout << "Xoa thanh cong.\n\n";

            if (pressAnyKey(c) == '1') main();
            else exit(0);
        default:
            cout << "Hay chon lai.\n\n";
            main();
    }
}

void xoaDS() {
    ofstream DSSV("danhsachsinhvien.txt", ofstream::out);
    DSSV.close();
}

void TimKiemTheoMa() {
    int id;

    cout << "Nhap ma can tim: ";
    cin >> id;

    for (int i = 0; i < n; i++)
        if (id == sv[i].id) {
            cout << "Sinh vien tim duoc:\n";
            cout << i + 1 << ".\n";
            cout << "Ma: " << sv[i].id << endl;
            cout << "Ho va ten: " << sv[i].ten << endl;
            cout << "Nam sinh: " << sv[i].ns << endl;
            cout << "Diem trung binh: " << sv[i].dtb << endl << endl;

            return;
        }
    cout << "Khong tim thay.\n\n";
}

void Nhap() {
    cout << "Nhap id: "; cin >> sv[n].id;
    fflush(stdin);
    cout << "Nhap ho ten: "; getline(cin, sv[n].ten);
    cout << "Nhap nam sinh: "; cin >> sv[n].ns;
    cout << "Nhap diem trung binh: "; cin >> sv[n].dtb;
    cout << endl;
}

void ghiFile() {
    ofstream DSSV("danhsachsinhvien.txt", ios::app);
    if (!DSSV) {
        cout << "Khong mo duoc file.\n";
        exit(0);
    }

    Nhap();

    DSSV << n + 1 << '.' << endl;
    DSSV << "Ma: " << sv[n].id << endl;
    DSSV << "Ho va ten: " << sv[n].ten << endl;
    DSSV << "Nam sinh: " << sv[n].ns << endl;
    DSSV << "Diem trung binh: " << sv[n].dtb << endl << endl;
    DSSV.close();
}

void docFile() {
    ifstream DSSV("danhsachsinhvien.txt");
    if (!DSSV) {
        cout << "Khong mo duoc file.\n";
        exit(0);
    }

    for (string str; getline(DSSV, str);)
        cout << str << endl;
    DSSV.close();
}