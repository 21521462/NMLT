#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

int n = 0;

struct SV {
    char ten[50];
    char lop[10];
    float dT, dL, dH;
} sv[MAX];

void nhapThongTinSV(SV &sv) {
    fflush(stdin);
    cout << "   Nhap ho va ten: ";
    gets(sv.ten);
    cout << "   Nhap lop: ";
    gets(sv.lop);
    cout << "   Nhap diem toan, ly, hoa: ";
    cin >> sv.dT >> sv.dL >> sv.dH;
    cout << endl;
}

void nhapSV(SV sv[], int &i) {
    cout << "   Nhap sinh vien thu " << i + 1 << ":\n\n";
    nhapThongTinSV(sv[i]);
    i++;
}

void xuatDSSV(SV sv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Ho va ten: " << sv[i].ten << endl;
        cout << "   Lop: " << sv[i].lop << endl;
        cout << "   Diem Toan, Ly, Hoa: ";
        cout << sv[i].dT << " " << sv[i].dL << " " << sv[i].dH << "\n\n";
    }
}

void timKiemTheoTen(SV sv[], int n) {
    SV svTimThay[MAX];
    int nsvTimThay = 0;
    char ten[50];
    cout << "   Nhap ten muon tim kiem: ";
    fflush(stdin);
    gets(ten);

    for (int i = 0; i < n; i++) {
        if (strstr(sv[i].ten, ten)) {
            svTimThay[nsvTimThay] = sv[i];
            nsvTimThay++;
        }
    }
    if (nsvTimThay != 0) {
        cout << "\n   Danh sach sinh vien tim duoc:\n\n";
        xuatDSSV(svTimThay, nsvTimThay);
    }
    else cout << "\n   Khong tim thay.\n\n";
}

void suaThongTinSV(SV &sv) {
    cout << "   Nhap ho va ten: ";
    fflush(stdin); gets(sv.ten);
    cout << "   Nhap lop: "; 
    gets(sv.lop);
    cout << "   Nhap diem toan, ly, hoa: ";
    cin >> sv.dT >> sv.dL >> sv.dH;
    cout << endl;
}

void suaSV(SV sv[], int n) {
    int m = 0, k;

    xuatDSSV(sv, n);

    cout << "   Nhap so thu tu sinh vien muon chinh sua: ";
    cin >> k;

    for (int i = 0; i < n; i++) {
        if (i + 1 == k) {
            m++;
            cout << endl << "   Sua thong tin sinh vien thu " << k << ":\n\n";
            suaThongTinSV(sv[i]);
        }
    }
    if (m == 0) cout << "\n   Khong tim thay\n\n";
}

void anPhim(char &c) {
    do {
        cout << "Bam phim 1 de tiep tuc, phim 0 de ket thuc: ";
        cin >> c;
    } while (c != '1' && c != '0');
}

int main() {
    int op;
    char c;

    cout << setw(10) << " " << "CHUONG TRINH QUAN LY SINH VIEN\n";
    cout << setfill('-');
    cout << setw(50) << "-" << endl;
    cout << "1. Them sinh vien\n";
    cout << "2. Xuat danh sach sinh vien\n";
    cout << "3. Tim kiem thong tin sinh vien\n";
    cout << "4. Chinh sua thong tin sinh vien\n";
    cout << setw(50) << "-" << endl;
    cout << setfill(' ');
    cout << "Nhap lua chon cua ban: "; cin >> op;

    switch (op) {
        case 1:
            cout << "1. Them sinh vien\n\n";
            nhapSV(sv, n);
            cout << "   Them sinh vien thanh cong.\n\n";

            anPhim(c);
            if (c == '1') main();
            else exit(0);
            break;
        case 2:
            cout << "2. Xuat danh sach sinh vien\n\n";
            if (n > 0) xuatDSSV(sv, n);
            else cout << "   Danh sach sinh vien trong.\n\n";

            anPhim(c);
            if (c == '1') main();
            else exit(0);
        case 3:
            cout << "3. Tim kiem thong tin sinh vien\n\n";
            if (n > 0) timKiemTheoTen(sv, n);
            else cout << "   Danh sach sinh vien trong.\n\n";

            anPhim(c);
            if (c == '1') main();
            else exit(0);
        case 4:
            cout << "4. Chinh sua thong tin sinh vien\n\n";
            if (n > 0) {
                cout << "   Danh sach sinh vien:\n\n";
                suaSV(sv, n);
            }
            else cout << "   Danh sach sinh vien trong.\n\n";

            anPhim(c);
            if (c == '1') main();
            else exit(0);
        default:
            cout << "Moi ban nhap lua chon khac!\n\n";
            main();
            break;
    }

    return 0;
}