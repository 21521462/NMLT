#include <iostream>
#include <cmath>

using namespace std;

struct DIEM {
    float x;
    float y;
};

typedef struct TAMGIAC {
    DIEM A;
    DIEM B;
    DIEM C;
} TG;

void nhap(TG &tg) {
    cout << "Nhap toa do dinh A: ";
    cin >> tg.A.x >> tg.A.y;
    cout << "Nhap toa do dinh B: ";
    cin >> tg.B.x >> tg.B.y;
    cout << "Nhap toa do dinh C: ";
    cin >> tg.C.x >> tg.C.y;
}

void xuat(TG tg) {
    cout << "Toa do dinh A: " << "(" << tg.A.x << ", " << tg.A.y << ")\n";
    cout << "Toa do dinh B: " << "(" << tg.B.x << ", " << tg.B.y << ")\n";
    cout << "Toa do dinh C: " << "(" << tg.C.x << ", " << tg.C.y << ")\n";
}

float doDai(float x, float y) {
    return sqrt(x * x + y * y);
}

float chuVi(TG tg) {
    float c = doDai(tg.A.x - tg.B.x, tg.A.y - tg.B.y);
    float a = doDai(tg.B.x - tg.C.x, tg.B.y - tg.C.y);
    float b = doDai(tg.C.x - tg.A.x, tg.C.y - tg.A.y);

    return a + b + c;
}

float dienTich(TG tg) {
    float p = chuVi(tg) / 2;
    float c = doDai(tg.A.x - tg.B.x, tg.A.y - tg.B.y);
    float a = doDai(tg.B.x - tg.C.x, tg.B.y - tg.C.y);
    float b = doDai(tg.C.x - tg.A.x, tg.C.y - tg.A.y);

    return sqrt(p * (p - c) * (p - a) * (p - b));
}

int main() {
    TG tg;

    nhap(tg);
    xuat(tg);

    cout << "Chu vi tam giac: " << chuVi(tg) << endl;
    cout << "Dien tich tam giac: " << dienTich(tg) << endl;

    return 0;
}