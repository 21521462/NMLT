#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define MAX 100

void Selection_main(int *p, int op);
void Selection_BTLT(int *p, int op);
void Nhap(int *p, int &n);
void NhapCoDK(int *p, int &n);
void Xuat(int *p, int n);
void xoaPhanTuAm(int *p, int n);
int xoaPhanTu(int *p, int k, int n);
int timKiem(int *p, int n);
bool pressAnyKey();
bool kiemTraSNT(int n);
bool isPrinted(int *p, int n);
bool isEven(int pi, int pj);
bool isPositiveFirst(int pi, int pj);
bool isExist(int *p, int pi, int i);
void BTBB(int *p);
void BTBB_Bai1(int *p, int n);
void BTBB_Bai2(int *p, int n);
void BTBB_Bai3(int *p, int n);
void BTBB_Bai4(int *p, int n);
void BTBB_Bai5(int *p, int n);
void BTLT(int *p);
void BTLT_Bai1_5(int *p, int n);
void BTLT_Bai6_14(int *p, int n);
void BTLT_Bai15_18(int *p, int n);
void BTLT_Bai19_31(int *p, int n);
void BTLT_Bai32_37(int *p, int n);
void BTLT_Bai38_44(int *p, int n);
void BTLT_Bai45_52(int *p, int n);

int main() {
    int *p = new int[MAX];
    int op;

    cout << setw(8) << ' ' << "MANG MOT CHIEU\n";
    cout << setfill('-');
    cout << setw(30) << '-' << endl;
    cout << "1. Bai tap bat buoc\n";
    cout << "2. Bai tap lam them\n";
    cout << setw(30) << '-' << endl;
    cout << setfill(' ');
    cout << "Nhap lua chon cua ban: "; cin >> op;

    Selection_main(p, op);
}

void Nhap(int *p, int &n) {
    do {
        cout << "Nhap so phan tu: ";
        cin >> n;
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> p[i];
    }
}

void NhapCoDK(int *p, int &n) {
    do {
        cout << "Nhap so phan tu n (5 < n < 100): ";
        cin >> n;
    } while (5 >= n || n >= 100);

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> p[i];
    }
}

void Xuat(int *p, int n) {
    cout << "Mang: ";

    for (int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout << endl;
}

void xoaPhanTuAm(int *p, int n) {
    for (int i = 0; i < n; i++)
        if (p[i] < 0) {
            for (int j = i; j < n; j++)
                p[j] = p[j + 1];
            n--;
            i--;
        }
    cout << "Mang sau khi xoa cac phan tu am: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";
}

void Selection_main(int *p, int op) {
    switch (op) {
        case 1:
            BTBB(p);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        case 2:
            BTLT(p);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        default:
            cout << "Hay chon lai.\n\n";
            main();
    }
}

void Selection_BTLT(int *p, int op) {
    int n;

    switch (op) {
        case 1:
            BTLT_Bai1_5(p, n);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        case 2:
            BTLT_Bai6_14(p, n);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        case 3:
            BTLT_Bai15_18(p, n);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        case 4:
            BTLT_Bai19_31(p, n);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        case 5:
            BTLT_Bai32_37(p, n);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        case 6:
            BTLT_Bai38_44(p, n);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        case 7:
            BTLT_Bai45_52(p, n);

            if (pressAnyKey()) main();
            else {
                delete[] p;
                exit(0);
            }
        default:
            cout << "Hay chon lai.\n\n";
            BTLT(p);
    }
}

int xoaPhanTu(int *p, int k, int n) {
    if (0 <= k && k < n) {
        for (int i = k; i < n; i++)
            p[i] = p[i + 1];

        n--;

        cout << "Mang sau khi khi xoa: ";

        for (int i = 0; i < n; i++)
            cout << p[i] << ' ';
        
        cout << endl;
        return 1;
    }
    else return 0;
}

int timKiem(int *p, int n) {
    int x;

    cout << "Nhap gia tri muon tim kiem: ";
    cin >> x;

    for (int i = 0; i < n; i++)
        if (p[i] == x) {
            cout << "Vi tri phan tu dau tien co gia tri bang " << x << " la ";
            return i;
        }

    return -1;
}

bool pressAnyKey() {
    int c;

    do {
        cout << "Nhap 1 de tiep tuc, 0 de ket thuc: ";
        cin >> c;
    } while (c != 0 && c != 1);

    if (c == 1) return true;
    return false;
}

bool kiemTraSNT(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

bool isPrinted(int *p, int n) {
    for (int i = 0; i < n; i++)
        if (p[i] == p[n]) return false;
    return true;
}

bool isEven(int pi, int pj) {
    if (abs(pi) % 2 == 0 && (pj) % 2 == 0 && pi < pj)
        return true;
    return false;
}

bool isPositiveFirst(int pi, int pj) {
    if (pi == 0) return true;
    if (pi < 0 && pj > 0) return true;
    if (pi > 0 && pj < 0) return false;

    return abs(pi) < abs(pj);
}

bool isExist(int *p, int pi, int i) {
    for (int j = 0; j < i; j++)
        if (p[j] == pi) return true;
    return false;
}

void BTBB(int *p) {
    int n;

    cout << setw(10) << ' ' << "BAI TAP BAT BUOC\n\n";
    BTBB_Bai1(p, n);
    BTBB_Bai2(p, n);
    BTBB_Bai3(p, n);
    BTBB_Bai4(p, n);
    BTBB_Bai5(p, n);
}

void BTBB_Bai1(int *p, int n) {
    cout << "1. Xuat cac so nguyen to trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);

    int k = 0;

    for (int i = 0; i < n; i++) {
        int m = 0;

        for (int j = 1; j <= sqrt(p[i]); j++)
            if (p[i] % j == 0) m++;

        if (m == 1 && p[i] != 1) {
            cout << p[i] << ' ';
            k++;
        }
    }

    if (k == 0)
        cout << "Mang khong co so nguyen to nao.\n\n";
    else
        cout << "la cac so nguyen to co trong mang.\n\n";
}

void BTBB_Bai2(int *p, int n) {
    cout << "2. Kiem tra mang doi xung\n\n";
    Nhap(p, n);
    Xuat(p, n);

    int m = 0;

    for (int i = 0; i < n / 2; i++)
        if (p[i] == p[n - 1 -i]) m++;

    if (m == n / 2)
        cout << "Day la mang doi xung.\n\n";
    else
        cout << "Day la mang khong doi xung.\n\n";
}

void BTBB_Bai3(int *p, int n) {
    int k;

    cout << "3. Xoa phan tu co chi so k\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap vi tri phan tu muon xoa: "; cin >> k;

    cout << xoaPhanTu(p, k, n) << "\n\n";
}

void BTBB_Bai4(int *p, int n) {
    int u = p[0], v = 0;

    cout << "4. Tim vi tri phan tu lon nhat trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);

    for (int i = 1; i < n; i++)
        if (u <= p[i]) {
            u = p[i];
            v = i;
        }
    
    cout << "Vi tri phan tu lon nhat: " << v << "\n\n";
}

void BTBB_Bai5(int *p, int n) {
    int u;

    cout << "5. Tim vi tri phan tu co gia tri am lon nhat trong mang so nguyen\n\n";
    Nhap(p, n);
    Xuat(p, n);

    for (int i = 0; i < n; i++)
        if (p[i] < 0) {
            u = i;
            break;
        }

    for (int i = u + 1; i < n; i++)
        if (p[i] < 0 && p[i] > p[u])
            u = i;

    if (p[u] < 0)
        cout << "Vi tri phan tu co gia tri am lon nhat: " << u << "\n\n";
    else
        cout << "Mang khong co phan tu am.\n\n";
}

void BTLT(int *p) {
    int op;

    cout << setw(7) << " " << "BAI TAP LAM THEM\n";
    cout << setfill('-');
    cout << setw(30) << '-' << endl;
    cout << "1. Cac thao tac nhap xuat\n";
    cout << "2. Cac thao tac tim kiem\n";
    cout << "3. Cac thao tac sap xep\n";
    cout << "4. Cac thao tac them/xoa/sua\n";
    cout << "5. Cac thao tac kiem tra\n";
    cout << "6. Cac thao tac tinh toan\n";
    cout << "7. Cac thao tac xu ly\n";
    cout << setw(30) << '-' << endl;
    cout << setfill(' ');
    cout << "Nhap lua chon cua ban: "; cin >> op;

    Selection_BTLT(p, op);
}

void BTLT_Bai1_5(int *p, int n) {
    cout << "1. Nhap mang so nguyen co n phan tu (n < n < 100)\n\n";
    NhapCoDK(p, n);
    Xuat(p, n);
    cout << endl;

    cout << "2. Tim kiem gia tri x trong mang so nguyen\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << timKiem(p, n) << "\n\n";

    cout << "3. In ra phan tu am cua mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    bool b = false;
    for (int i = 0; i < n; i++)
        if (p[i] < 0) {
            b = true;
            break;
        }
    if (b) {
        cout << "Cac phan tu am cua mang la: ";
        for (int i = 0; i < n; i++)
            if (p[i] < 0)
                cout << p[i] << " ";
        cout << "\n\n";
    }
    else cout << "Mang khong co phan tu am.\n\n";

    cout << "4. In ra cac phan tu co gia tri le cua mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    b = false;
    for (int i = 0; i < n; i++)
        if (abs(p[i]) % 2 == 1) {
            b = true;
            break;
        }
    if (b) {
        cout << "Cac phan tu le cua mang: ";
        for (int i = 0; i < n; i++)
            if (abs(p[i]) % 2 == 1) cout << p[i] << " ";
        cout << "\n\n";
    }
    else cout << "Mang khong co phan tu le.\n\n";

    cout << "5. In ra cac phan tu chan va nho hon 20\n\n";
    Nhap(p, n);
    Xuat(p, n);
    b =  false;
    for (int i = 0; i < n; i++)
        if (abs(p[i]) % 2 == 0 && p[i] < 20) {
            b = true;
            break;
        }
    if (b) {
        cout << "Cac phan tu chan va nho hon 20: ";
        for (int i = 0; i < n; i++)
            if (p[i] < 20 && abs(p[i]) % 2 == 0)
                cout << p[i] << " ";
        cout << "\n\n";
    }
}

void BTLT_Bai6_14(int *p, int n) {
    int x, *q = new int[MAX];
    bool b = false;

    cout << "6. Vi tri cuoi cung cua phan tu x trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap gia tri muon tim kiem: "; cin >> x;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] == x) {
            b = true;
            cout << "Vi tri cuoi cung cua phan tu co gia tri bang " << x << ": " << i << "\n\n";
            break;
        }
    }
    if (!b) cout << "Khong tim thay.\n\n";

    cout << "7. Vi tri so nguyen to dau tien trong mang neu co\n\n";
    Nhap(p, n);
    Xuat(p, n);
    b = false;
    for (int i = 0; i < n; i++)
        if(kiemTraSNT(p[i])) {
            b = true;
            cout << "Vi tri so nguyen to dau tien: " << i << "\n\n";
            break;
        }
    if (!b) cout << "Mang khong co so nguyen to.\n\n";

    cout << "8. So nho nhat trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    x = p[0];
    for (int i = 1; i < n; i++)
        x = min(x, p[i]);
    cout << "So nho nhat trong mang: " << x << "\n\n";

    cout << "9. So lon nhat trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    x = p[0];
    for (int i = 1; i < n; i++)
        x = max(x, p[i]);
    cout << "So lon nhat trong mang: " << x << "\n\n";

    cout << "10. So duong nho nhat/lon nhat trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int M = 0, m;
    for (int i = 0; i < n; i++)
        M = max(M, p[i]);
    m = M;
    for (int i = 0; i < n; i++)
        if (m > p[i] && p[i] > 0) m = p[i];

    if (M > 0 && m > 0)
        cout << "So duong lon nhat/nho nhat: " << M << '/' << m << "\n\n";
    else
        cout << "10. Mảng không có số dương.\n\n";

    cout << "11. Vi tri phan tu co gia tri x xuat hien cuoi cung\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap gia tri muon tim kiem: "; cin >> x;
    b = false;
    for (int i = n - 1; i >= 0; i--)
        if (p[i] == x) {
            b = true;
            cout << "Vi tri cuoi cung cua phan tu co gia tri bang " << x << ": " << i << "\n\n";
            break;
        }

    if (!b) cout << "Khong tim thay.\n\n";

    cout << "12. Vi tri cua phan tu nho nhat trong mang 1 chieu\n\n";
    Nhap(p, n);
    Xuat(p, n);
    m = p[0], x = 0;
    for (int i = 1; i < n; i++)
        m = min(m, p[i]);
    for (int i = 0; i < n; i++)
        if (p[i] == m) {
            q[x] = i;
            x++;
        }
    cout << "Vi tri phan tu nho nhat trong mang: ";
    for (int i = 0; i < x; i++)
        cout << q[i] << " ";
    cout << "\n\n";
    
    cout << "13. Vi tri phan tu lon nhat trong mang 1 chieu\n\n";
    Nhap(p, n);
    Xuat(p, n);
    M = p[0], x = 0;
    for (int i = 1; i < n; i++)
        m = max(m, p[i]);
    for (int i = 0; i < n; i++)
        if (p[i] == m) {
            q[x] = i;
            x++;
        }
    cout << "Vi tri phan tu lon nhat trong mang: ";
    for (int i = 0; i < x; i++)
        cout << q[i] << " ";
    cout << "\n\n";

    cout << "14. Phan tu xuat hien nhieu nhat trong mang so nguyen\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++) {
        x = 0;
        for (int j = 0; j < n; j++)
            if (p[i] == p[j]) x++;
        q[i] = x;
    }
    M = q[0];
    for (int i = 1; i < n; i++)
        M = max(M, q[i]);
    cout << "Phan tu xuat hien nhieu nhat: ";
    for (int i = 0; i < n; i++)
        if (q[i] == M && isPrinted(p, i))
            cout << p[i] << " ";
    cout << "\n\n";
    delete[] q;
}

void BTLT_Bai15_18(int *p, int n) {
    cout << "15. Sap xep mang theo thu tu giam dan\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i] < p[j]) swap(p[i], p[j]);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "16. Sap xep cac phan tu chan giam dan\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isEven(p[i], p[j])) swap(p[i], p[j]);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "17. Sap xep cac phan tu am duong trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i] > 0 && p[j] < 0) swap(p[i], p[j]);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "18. Sap xep mang sao cho cac so duong dung\ndau mang giam dan, ke den la cac so am tang dan,\ncuoi cung la cac so 0\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isPositiveFirst(p[i], p[j])) swap(p[i], p[j]);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";
}

void BTLT_Bai19_31(int *p, int n) {
    cout << "19. Xoa phan tu tai vi tri le trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++)
            p[j] = p[j + 1];
        n--;
    }
    cout << "Mang sau khi xoa phan tu tai vi tri le: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "20. Xoa phan tu co gia tri lon nhat trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int M = p[0], iM = 0;
    for (int i = 1; i < n; i++)
        if (M < p[i]) {
            M = p[i];
            iM = i;
        }
    for (int i = iM; i < n; i++)
        p[i] = p[i + 1];
    n--;
    cout << "Mang sau khi xoa phan tu lon nhat: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";;
    cout << "\n\n";

    cout << "21. Xoa tat ca cac phan tu nho hon X\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap X: "; cin >> M;
    for (int i = 0; i < n; i++)
        if (p[i] < M) {
            for (int j = i; j < n; j++)
                p[j] = p[j + 1];
            n--;
            i--;
        }
    cout << "Mang sau khi xoa cac phan tu nho hon " << M << ": ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "22. Xoa phan tu co gia tri gan X nhat\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap X: "; cin >> M;
    int d = abs(p[0] - M), c = 0;
    for (int i = 0; i < n; i++)
        if (abs(p[i] - M) < d)
            d = abs(p[i] - M);
    for (int i = 0; i < n; i++)
        if (abs(p[i] - M) == d) {
            for (int j = i; j < n; j++)
                p[j] = p[j + 1];
            i--;
            n--;
        }
    cout << "Mang sau khi xoa phan tu co gia tri gan " << M << " nhat: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "23. Chen X vao vi tri dau cua mang mot chieu\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap X: "; cin >> M;
    n++;
    for (int i = n - 1; i >= 1; i--)
        p[i] = p[i - 1];
    p[0] = M;
    cout << "Mang sau khi chen " << M << " vao vi tri dau: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "24. Chen X vao phia sau phan tu co gia tri lon nhat trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap X: "; cin >> c;
    M = p[0];
    for (int i = 1; i < n; i++)
        M = max(M, p[i]);
    for (int i = 0; i < n; i++)
        if (p[i] == M) {
            n++;
            for (int j = n - 1; j > i + 1; j--)
                p[j] = p[j - 1];
            p[i + 1] = c;
        }
    cout << "Mang sau khi chen " << c << " vao phia sau phan tu lon nhat: "; 
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "25. Chen phan tu X vao tat ca cac phan tu chan trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap X: "; cin >> c;
    for (int i = 0; i < n; i++)
        if (abs(p[i]) % 2 == 0) {
            n++;
            for (int j = n - 1; j > i ; j--) {
                if (j == i + 1) p[j] = c;
                else p[j] = p[j - 1];
            }
            i++;
        }
    cout << "Mang sau khi chen " << c << " vao phia sau tat ca phan tu chan: "; 
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "26. Them so 0 dang sau cac so nguyen to trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++)
        if (kiemTraSNT(p[i])) {
            n++;
            for (int j = n - 1; j > i; j--) {
                if (j == i + 1) p[j] = 0;
                else p[j] = p[j - 1];
            }
        }
    cout << "Mang sau khi them so 0 dang sau cac so nguyen to: ";
    for (int i = 0; i< n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "27. Xoa tat ca so nguyen to trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++)
        if (kiemTraSNT(p[i])) {
            for (int j = i; j < n; j++)
                p[j] = p[j + 1];
            n--;
            i--;
        }
    cout << "Mang sau khi xoa tat ca so nguyen to: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "28. Sua cac so nguyen to co trong mang thanh so 0\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n; i++)
        if (kiemTraSNT(p[i]))
            p[i] = 0;
    cout << "Mang sau khi sua cac so nguyen to thanh so 0: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "29. Viet ham xoa tat ca cac phan tu co gia tri la so am\ntrong mang so nguyen a co n phan tu\n\n";
    Nhap(p, n);
    Xuat(p, n);
    xoaPhanTuAm(p, n);

    cout << "30. Xoa cac phan tu trung voi X trong mang 1 chieu\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap X: "; cin >> c;
    for (int i = 0; i < n; i++)
        if (p[i] == c) {
            for (int j = i; j < n; j++)
                p[j] = p[j + 1];
            n--;
            i--;
        }
    cout << "Mang sau khi xoa cac phan tu trung voi " << c << ": ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "31. Chen X vao day sao cho day van co thu tu tang dan\n\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap X: "; cin >> c;
    cout << "Mang sau khi sap xep tang dan: ";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (p[i] > p[j]) swap(p[i], p[j]);
        cout << p[i] << " ";
    }
    cout << endl;
    cout << "Mang sau khi chen " << c << " de day van tang dan: ";
    for (int i = 0; i < n; i++) {
        if (c >= p[n - 1]) {
            n++;
            p[n] = p[n - 1];
            p[n - 1] = c;
            break;
        }
        if (c <= p[i]) {
            n++;
            for (int j = n - 1; j > i; j--)
                p[j] = p[j - 1];
            p[i] = c;
            break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";
}

void BTLT_Bai32_37(int *p, int n) {
    cout << "32. Mang co phai la mang toan chan/toan le?\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int c = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] % 2 == 0) c++;
        else l++;
    }
    if (c == n) cout << "Mang toan chan.\n\n";
    else if (l == n) cout << "Mang toan le.\n\n";
    else cout << "Mang khong toan chan cung khong toan le.\n\n";

    cout << "33. Mang co phai la mang toan so nguyen to?\n\n";
    Nhap(p, n);
    Xuat(p, n);
    bool b = true;
    for (int i = 0; i < n; i++)
        if (!kiemTraSNT(p[i])) {
            b = false;
            cout << "Mang khong toan so nguyen to.\n\n";
            break;
        }
    if (b) cout << "Mang toan so nguyen to.\n\n";

    cout << "34. Mang co phai la mang tang dan/giam dan?\n\n";
    Nhap(p, n);
    Xuat(p, n);
    c = 0, l = 0;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] < p[i + 1]) c++;
        if (p[i] > p[i + 1]) l++;
    }
    if (c == n - 1) cout << "Mang tang dan.\n\n";
    else if (l == n - 1) cout << "Mang giam dan.\n\n";
    else cout << "Mang khong tang dan cung khong giam dan.\n\n";

    cout << "35. Mang co doi xung hay khong?\n\n";
    Nhap(p, n);
    Xuat(p, n);
    c = 0;
    for (int i = 0; i < n / 2; i++)
        if (p[i] == p[n - 1 - i]) c++;
    if (c == n / 2) cout << "Mang doi xung.\n\n";
    else cout << "Mang khong doi xung.\n\n";

    cout << "36. Mang C co phai la mang con cua mang B?\n\n";
    int *q = new int[MAX], m;
    cout << "Nhap mang A\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap mang B\n";
    Nhap(q, m);
    Xuat(q, m);
    if (m < n) {   
        do {
            cout << "Nhap so phan tu day B >= day A\n";
            Nhap(q, m);
        } while (m < n);
    }
    int a = p[0];
    for (int i = 0; i < m; i++) {
        if (q[i] == a) {
            int dem = 1, b = 1;
            for (int j = i + 1; b < n; j++, b++)
                if (q[j] == p[n]) dem++;
            if (dem == n) {
                cout << "Mang A la mang con cua B.\n\n";
                break;
            }
        }
        if (i == m - 1)
            cout << "Mang A khong la mang con cua B.\n\n";
    }
    delete[] q;

    cout << "37. Mang co thu tu tang hay khong?\n\n";
    Nhap(p, n);
    Xuat(p, n);
    m = 0;
    for (int i = 0; i < n - 1; i++)
        if (p[i] > p[i + 1]) m++;
    if (m == 0) cout << "Mang co thu tu tang.\n\n";
    else cout << "Mang khong co thu tu tang.\n\n";
}

void BTLT_Bai38_44(int *p, int n) {
    cout << "38. Dem cac phan tu chia het cho 2\nnhung khong chia het cho 4\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (abs(p[i]) % 2 == 0 && p[i] % 4 != 0)
            dem++;
    cout << "So phan tu chia het cho 2 nhung khong chia het cho 4: " << dem << "\n\n";

    cout << "39. Tinh tong cac so nguyen to co trong mang.\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int S = 0;
    for (int i = 0; i < n; i++)
        if (kiemTraSNT(p[i]))
            S += p[i];
    cout << "Tong cac so nguyen to: " << S << "\n\n";

    cout << "40. Tinh tong cac so chan/le trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int Sc = 0, Sl = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] % 2 == 0) Sc += p[i];
        else Sl += p[i];
    }
    cout << "Tong cac phan tu chan: " << Sc << endl;
    cout << "Tong cac phan tu le: " <<  Sl << "\n\n";

    cout << "41. Tong cac phan tu o vi tri chan\n\n";
    Nhap(p, n);
    Xuat(p, n);
    S = 0;
    for (int i = 0; i < n; i += 2)
        S += p[i];
    cout << "Tong cac phan tu o vi tri chan: " << S << "\n\n";

    cout << "42. Tinh tong cac phan tu cuc dai\n\n";
    Nhap(p, n);
    Xuat(p, n);
    S = 0;
    for (int i = 1; i < n - 1; i++)
        if (p[i - 1] < p[i] && p[i] > p[i + 1])
            S += p[i];
    cout << "Tong cac phan tu cuc dai: " << S << "\n\n";

    cout << "43. Tinh tong cac phan tu cuc tieu\n\n";
    Nhap(p, n);
    Xuat(p, n);
    S = 0;
    for (int i = 1; i < n - 1; i++)
        if (p[i - 1] > p[i] && p[i] < p[i + 1])
            S += p[i];
    cout << "Tong cac phan tu cuc tieu: " << S << "\n\n";

    cout << "44. Tinh tong cac phan tu xung quanh\n\n";
    Nhap(p, n);
    Xuat(p, n);
    S = 0;
    for (int i = 1; i < n - 1; i++)
        if (p[i] == p[i + 1] + p[i - 1])
            S += p[i];
    cout << "Tong cac phan tu xung quanh: " << S << "\n\n";
}

void BTLT_Bai45_52(int *p, int n) {
    cout << "45. Tach cac so nguyen to tu mang a sang mang b\n\n";
    cout << "Nhap mang a\n";
    Nhap(p, n);
    Xuat(p, n);
    int *q = new int[MAX], m = 0;
    for (int i = 0; i < n; i++)
        if (kiemTraSNT(p[i])) {
            q[m] = p[i];
            m++;
        }
    cout << endl << "Mang b (chua cac so nguyen to): ";
    for (int i = 0; i < m; i++)
        cout << q[i] << " ";
    cout << "\n\n";

    cout << "46. Tach mang a thanh 2 mang b (chua cac so\nnguyen duong) va c (chua cac so con lai)\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int *r = new int[MAX], o = 0;
    m = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] > 0) {
            q[m] = p[i];
            m++;
        }
        else {
            r[o] = p[i];
            o++;
        }
    }
    cout << endl << "Mang b (chua cac so nguyen duong): ";
    for (int i = 0; i < m; i++)
        cout << q[i] << " ";
    cout << endl << "Mang c (chua cac so con lai): ";
    for (int i = 0; i < o; i++)
        cout << r[i] << " ";
    cout << "\n\n";

    cout << "47. Tach 1 mang thanh 2 mang chan va le\n\n";
    Nhap(p, n);
    Xuat(p, n);
    m = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] % 2 == 0) {
            q[m] = p[i];
            m++;
        }
        else {
            r[o] = p[i];
            o++;
        }
    }
    cout << endl << "Mang gom cac so chan: ";
    for (int i = 0; i < m; i++)
        cout << q[i] << " ";
    cout << endl << "Mang gom cac so le: ";
    for (int i = 0; i < o; i++)
        cout << r[i] << " ";
    cout << "\n\n";

    cout << "48. Noi 2 mang so nguyen\n\n";
    cout << "Nhap mang goc\n";
    Nhap(p, n);
    Xuat(p, n);
    cout << "Nhap mang noi\n";
    Nhap(q, m);
    Xuat(q, m);
    n += m;
    for (int i = n - m; i < n; i++)
        p[i] = q[i - n + m];
    cout << endl << "Mang goc sau khi noi: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "49. Kiem tra phan tu mang 1 chieu khi nhap tu ban phim\n\n";
    do {
        cout << "Nhap so phan tu: "; cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++) {
        cout << "p[" << i << "] = ";
        cin >> p[i];

        while (isExist(p, p[i], i)) {
            cout << "Hay nhap lai: " << endl;
            cout << "p[" << i << "] = ";
            cin >> p[i];
        }
    }
    Xuat(p, n);
    cout << endl;

    cout << "50. Chi ra so hang lon thu k cua mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    int k, bk, b[MAX];
    for (int i = 0; i < n; i++)
        b[i] = p[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (b[i] < b[j])
                swap(b[i], b[j]);
    do {
        cout << endl << "Nhap k: ";
        cin >> k;
    } while (k <= 0);
    m = k;
    for (int i = 0; m > 0; i++)
        if (b[i] > b[i + 1]) {
            bk = b[i];
            m--;
        }
    cout << "Phan tu lon thu " << k << " cua mang: " << bk << "\n\n";

    cout << "51. Dao nguoc day so\n\n";
    Nhap(p, n);
    Xuat(p, n);
    for (int i = 0; i < n / 2; i++)
        swap(p[i], p[n - 1 - i]);
    cout << endl << "Mang sau khi nghich dao: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n\n";

    cout << "52. Dem so luong mang con tang co trong mang\n\n";
    Nhap(p, n);
    Xuat(p, n);
    m = 0;
    for (int i = 0; i < n; i++)
        if (p[i] >= p[i + 1]) m++;
    cout << endl << "So mang con tang: " << m + 1 << "\n\n";
}