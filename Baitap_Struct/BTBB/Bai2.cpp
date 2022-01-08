#include <iostream>
#include <cmath>

using namespace std;

#define MAX 100

struct mDiem {
    int x;
    int y;

    float module() {
        return sqrt(x * x + y * y);
    }
} diem[MAX];

struct Diem {
    int x;
    int y;
} diem1, diem2;

float KC(Diem d1, Diem d2) {
    return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
}

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

int main() {
    int n;
    srand((int)time(0));

    cout << "Nhap toa do diem 1: ";
    cin >> diem1.x >> diem1.y;
    cout << "Nhap toa do diem 2: ";
    cin >> diem2.x >> diem2.y;
    cout << "Khoang cach giua hai diem: " << KC(diem1, diem2) << "\n\n";

    cout << "Nhap so diem cua mang: "; cin >> n;

    for (int i = 0; i < n; i++) {
        diem[i].x = randInt(-5, 5);
        diem[i].y = randInt(-5, 5);

        cout << "Toa do diem " << i + 1 << ": ";
        cout << '(' << diem[i].x << ", " << diem[i].y << ")\n";
    }

    float M = diem[0].module(), m = diem[0].module();
    int iM = 0, im = 0;

    for (int i = 1; i < n; i++) {
        if (M != max(M, diem[i].module())) iM = i;
        if (m != min(m, diem[i].module())) im = i;
    }

    cout << "Diem trong mang gan goc toa do nhat: ";
    cout << '(' << diem[im].x << ", " << diem[im].y << ")\n";
    cout << "Diem trong mang xa goc toa do nhat: ";
    cout << '(' << diem[iM].x << ", " << diem[iM].y << ")\n";

    return 0;
}