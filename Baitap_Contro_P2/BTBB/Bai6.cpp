#include <iostream>

using namespace std;

#define MAX 100

void Nhap(float **&p, int &r, int &c, char ch) {
    do {
        cout << "   Nhap so dong (dong > 0), so cot (cot > 0) cua ma tran " << ch << ": ";
        cin >> r >> c;
    } while (r * c == 0 || r < 0 || c < 0);

    for (int i = 0; i < r; i++)
        p[i] = new float[c];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cout << "   " << ch << '[' << i + 1 << "][" << j + 1 << "] = ";
            cin >> p[i][j];
        }

    cout << endl;
}

void Xuat(float **p, int r, int c, char ch) {
    cout << "   Ma tran " << ch << ":\n";

    for (int i = 0; i < r; i++) {
        cout << "   ";

        for (int j = 0; j < c; j++)
            cout << p[i][j] << ' ';

        cout << endl;
    }

    cout << endl;
}

void Bai1_BTBB() {
    float **pA = new float*[MAX], **pB = new float*[MAX];
    int ra, ca, rb, cb;

    cout << "1. CONG HAI MA TRAN\n\n";
    Nhap(pA, ra, ca, 'A');
    Nhap(pB, rb, cb, 'B');

    while (ra != rb || ca != cb) {
        cout << "   Hai ma tran khong cung kich thuoc. Hay nhap lai.\n\n";
        Nhap(pA, ra, ca, 'A');
        Nhap(pB, rb, cb, 'B');
    }

    Xuat(pA, ra, ca, 'A');
    Xuat(pB, rb, cb, 'B');

    cout << "   Tong hai ma tran:\n";

    for (int i = 0; i < ra; i++) {
        cout << "   ";

        for (int j = 0; j < ca; j++)
            cout << pA[i][j] + pB[i][j] << ' ';

        cout << endl;
    }

    for (int i = 0; i < ra; i++)
        delete[] pA[i], pB[i];
    
    delete[] pA, pB;
    cout << endl;
}

float tinhPhanTu(float **pA, float **pB, int r, int c, int m) {
    float S = 0;

    for (int i = 0; i < m; i++)
        S += pA[r][i] * pB[i][c];
    
    return S;
}

void Bai2_BTBB() {
    float **pA = new float*[MAX], **pB = new float*[MAX];
    int ra, ca, rb, cb;

    cout << "2. NHAN HAI MA TRAN\n\n";
    Nhap(pA, ra, ca, 'A');
    Nhap(pB, rb, cb, 'B');

    while (ca != rb && cb != ra) {
        cout << "   Loi kich thuoc. Hay nhap lai.";
        Nhap(pA, ra, ca, 'A');
        Nhap(pB, rb, cb, 'B');
    }

    Xuat(pA, ra, ca, 'A');
    Xuat(pB, rb, cb, 'B');

    if (ca == rb) {
        cout << "   Tich AB:\n";

        for (int i = 0; i < ra; i++) {
            cout << "   ";

            for (int j = 0; j < cb; j++)
                cout << tinhPhanTu(pA, pB, i, j, ca) << ' ';

            cout << endl;
        }

        cout << endl;
    }
    if (cb == ra) {
        cout << "   Tich BA:\n";

        for (int i = 0; i < rb; i++) {
            cout << "   ";

            for (int j = 0; j < ca; j++)
                cout << tinhPhanTu(pB, pA, i, j, cb) << ' ';

            cout << endl;
        }

        cout << endl;
    }

    for (int i = 0; i < ra; i++)
        delete[] pA[i];
    for (int i = 0; i < rb; i++)
        delete[] pB[i];
    delete[] pA, pB;
}

void Bai3_BTBB() {
    float **p = new float*[MAX];
    int r, c, S = 0;

    cout << "3. TINH TONG CAC GIA TRI LON NHAT TREN MOI DONG\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    for (int i = 0; i < r; i++) {
        float M = p[i][0];

        for (int j = 1; j < c; j++)
            M = max(M, p[i][j]);
        
        S += M;
    }

    cout << "   Tong cac gia tri lon nhat tren moi dong: " << S << "\n\n";

    for (int i = 0; i < r; i++)
        delete[] p[i];
    delete[] p;
}

void Bai1_BTLT() {
    float **p = new float*[MAX];
    int r, c;

    cout << "1. NHAP MANG/XUAT MANG\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    for (int i = 0; i < r; i++)
        delete[] p;
}

int timPhanTu(float **p, int r, int c, float f) {
    int m = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (p[i][j] == f) m++;

    return m;
}

void Bai2_BTLT() {
    float **p = new float*[MAX], f;
    int r, c;

    cout << "2. TIM KIEM MOT PHAN TU TRONG MANG\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    cout << "   Nhap phan tu muon tim kiem: "; cin >> f;
    cout << endl;

    if(timPhanTu(p, r, c, f) == 0)
        cout << "   Khong tim thay.";
    else {
        cout << "   Vi tri tim thay: ";

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (p[i][j] == f)
                    cout << '(' << i + 1 << ", " << j + 1<< ") ";
    }

    cout << "\n\n";

    for (int i = 0; i < r; i++)
        delete[] p[i];
    delete[] p;
}

void Bai3_BTLT() {
    float **p = new float*[MAX];
    int r, c;

    cout << "3. KIEM TRA MA TRAN DOI XUNG\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    if (r != c) cout << "   Ma tran khong co duong cheo chinh.\n\n";
    else {
        for (int i = 0; i < r; i++)
            for (int j = i + 1; j < c; j++)
                if (p[i][j] != p[j][i]) {
                    cout << "   Ma tran khong doi xung.\n\n";
                    return;
                }
        
        cout << "   Ma tran doi xung.\n\n";
    }

    for (int i = 0; i < r; i++)
        delete[] p[i];
    delete[] p;
}

void TongPT_Dong(float **p, int r, int c) {
    cout << "   Tong phan tu tren dong:\n";

    for (int i = 0; i < r; i++) {
        int S = 0;

        cout << "   Dong " << i + 1 << ": ";

        for (int j = 0; j < c; j++)
            S += p[i][j];

        cout << S << endl;
    }

    cout << endl;
}

void TongPT_Cot(float **p, int r, int c) {
    cout << "   Tong phan tu tren cot:\n";

    for (int j = 0; j < c; j++) {
        int S = 0;

        cout << "   Cot " << j + 1 << ": ";

        for (int i = 0; i < r; i++)
            S += p[i][j];

        cout << S << endl;
    }

    cout << endl;
}

void TongPT_ToanMang(float **p, int r, int c) {
    int S = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            S += p[i][j];
    
    cout << "   Tong phan tu toan mang: " << S << "\n\n";
}

void TongPT_DuongCheoChinh(float **p, int r, int c) {
    if (r != c) cout << "   Ma tran khong co duong cheo chinh.\n\n";
    else {
        int S = 0;

        for (int i = 0; i < r; i++)
            S += p[i][i];

        cout << "   Tong phan tu tren duong cheo chinh: " << S << "\n\n";
    }
}

void TongPT_NuaTren(float **p, int r, int c) {
    if (r != c) cout << "   Ma tran khong co nua tren.\n\n";
    else {
        int S = 0;

        for (int i = 0; i < r; i++)
            for (int j = i; j < c; j++)
                S += p[i][j];

        cout << "   Tong phan tu tren nua tren: " << S << "\n\n";
    }
}

void TongPT_NuaDuoi(float **p, int r, int c) {
    if (r != c) cout << "   Ma tran khong co nua duoi.\n\n";
    else {
        int S = 0;

        for (int i = 0; i < r; i++)
            for (int j = 0; j <= i; j++)
                S += p[i][j];
        
        cout << "   Tong phan tu tren nua duoi: " << S << "\n\n";
    }
}

void Bai4_BTLT() {
    float **p = new float*[MAX];
    int r, c;

    cout << "4. TONG CAC PHAN TU TREN DONG/COT/TOAN\n   MANG/DUONG CHEO CHINH/NUA TREN/NUA DUOI\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    TongPT_Dong(p, r, c);
    TongPT_Cot(p, r, c);
    TongPT_ToanMang(p, r, c);
    TongPT_DuongCheoChinh(p, r, c);
    TongPT_NuaTren(p, r, c);
    TongPT_NuaDuoi(p, r, c);

    for (int i = 0; i < r; i++)
        delete[] p[i];
    delete[] p;
}

void Bai5_BTLT() {
    float **p = new float*[MAX];
    int r, c;

    cout << "5. TIM GIA TRI NHO NHAT/LON NHAT CUA MANG\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    float m = p[0][0], M = p[0][0];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            M = max(M, p[i][j]);
            m = min(m, p[i][j]);
        }

    cout << "   Phan tu nho nhat, lon nhat trong mang: " << m << ", " << M << "\n\n";

    for (int i = 0; i < r; i++)
        delete[] p[i];
    delete[] p;
}

float dinhThuc(float **p, int r, int c) {
    float S = 0, s;

    if (r == 1) return p[0][0];
    if (r == 2) return p[0][0] * p[1][1] - p[1][0] * p[0][1];

    for (int k = 0; k < r; k++) {
        float **phanBu = new float*[r - 1];

        for (int i = 0; i < r; i++)
            phanBu[i] = new float[c - 1];

        for (int i = 0; i < r; i++)
            for (int j = 1; j < c; j++) {
                if (i > k) phanBu[i - 1][j - 1] = p[i][j];
                else if (i < k) phanBu[i][j - 1] = p[i][j];
            }

        if (k % 2 == 0) s = 1;
        else s = -1;

        S += p[k][0] * s * dinhThuc(phanBu, r - 1, c - 1);
    }

    return S;
}

void Bai6_BTLT() {
    float **p = new float*[MAX];
    int r, c;

    cout << "6. TINH DINH THUC MA TRAN\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    while (r != c) {
        cout << "   Ma tran vua nhap khong phai la ma tran vuong.\n";
        cout << "   Hay nhap mot ma tran vuong de tinh dinh thuc.\n\n";
        Nhap(p, r, c, 'A');
        Xuat(p, r, c, 'A');
    }

    cout << "   Dinh thuc cua ma tran A: " << dinhThuc(p, r, c) << "\n\n";

    for (int i = 0; i < r; i++)
        delete[] p[i];
    delete[] p;
}

void Bai7_BTLT() {
    float **p = new float*[MAX];
    int r, c;

    cout << "7. KIEM TRA MA TRAN DON VI\n\n";
    Nhap(p, r, c, 'A');
    Xuat(p, r, c, 'A');

    if (r != c) cout << "   Ma tran da cho khong phai ma tran don vi.\n\n";
    else {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (i == j && p[i][j] != 1 || i != j && p[i][j] != 0) {
                    cout << "   Ma tran da cho khong phai la ma tran don vi.\n\n";
                    return;
                }

        cout << "   Ma tran da cho la ma tran don vi.\n\n";
    }

    for (int i = 0; i < r; i++)
        delete[] p[i];
    delete[] p;
}

int main() {
    Bai1_BTBB();
    Bai2_BTBB();
    Bai3_BTBB();
    Bai1_BTLT();
    Bai2_BTLT();
    Bai3_BTLT();
    Bai4_BTLT();
    Bai5_BTLT();
    Bai6_BTLT();
    Bai7_BTLT();

    return 0;
}