#include <iostream>

using namespace std;

struct TG {
    int h;
    int m;
    int s;

    void nhap() {
        cin >> h >> m >> s;
    }

    void xuat() {
        cout << h << "h " << m << "m " << s << "s.\n\n";
    }

    int quyDoi() {
        return h * 3600 + m * 60 + s;
    }
} t1, t2;

void KC() {
    int a =  abs(t1.quyDoi() - t2.quyDoi());
    
    TG t3 = {
        a / 3600,
        (a / 60) % 60,
        a % 60
    };

    t3.xuat();
}

int main() {
    cout << "Nhap moc thoi gian 1: ";
    t1.nhap();
    cout << "Nhap moc thoi gian 2: ";
    t2.nhap();

    cout << "Khoang cach giua hai moc thoi gian: ";
    KC();

    return 0;
}