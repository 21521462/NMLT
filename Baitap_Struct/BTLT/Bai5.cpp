#include <iostream>

using namespace std;

/*int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}*/

struct SoPhuc {
    int a;
    int b;

    void nhap() {
        cin >> a >> b;
        /*a = randInt(-10, 10);
        b = randInt(-10, 10);*/
    }

    void xuat() {
        if (a == b && a == 0) cout << 0 << "\n\n";
        else if (a == 0) {
            if (b == 1) cout << "i\n\n";
            else if (b == -1) cout << "- i\n\n";
            else {
                if (b < 0) cout << "- " <<  -b << "i\n\n";
                else cout << b << "i\n\n";
            }
        }
        else if (b == 0) {
            if (a > 0) cout << a << "\n\n";
            else cout << "- " << -a << "\n\n";
        }
        else {
            if (b < 0) {
                if (b == -1) cout << a << ' ' << "- i\n\n";
                else cout << a << " - " << -b << "i\n\n";
            }
            else {
                if (b == 1) cout << a << " + " << "i\n\n";
                else cout << a << " + " << b << "i\n\n";
            }
        }
    }
} z1, z2;

int UCLN(int a, int b) {
    if (abs(a) == abs(b)) return abs(a);
    else if (abs(a) < abs(b)) return UCLN(abs(a), abs(b - a));
    else return UCLN(abs(a - b), abs(a));
}

void Tong() {
    SoPhuc z = {
        z1.a + z2.a,
        z1.b + z2.b
    };

    cout << "z1 + z2 = ";
    z.xuat();
}

void Hieu() {
    SoPhuc z = {
        z1.a - z2.a,
        z1.b - z2.b
    };

    cout << "z1 - z2 = ";
    z.xuat();
}

void Tich() {
    SoPhuc z = {
        z1.a * z2.a - z1.b * z2.b,
        z1.a * z2.b + z1.b * z2.a
    };

    cout << "z1 * z2 = ";
    z.xuat();
}

void Thuong() {
    if (z2.a == 0 && z2.b == 0) cout << "Khong chia duoc.\n\n";
    else {
        int c = z2.a * z2.a + z2.b * z2.b;
        int a = z1.a * z2.a - z1.b * (-z2.b);
        int b = z1.a * (-z2.b) + z1.b * z2.a;

        cout << "z1 / z2 = ";

        if (a % c == 0 && b % c == 0) {
            SoPhuc z = {
                a / c,
                b / c,
            };

            z.xuat();
        }
        else if (a % c == 0) {
            int u = UCLN(b, c);
            
            if (a == 0) {
                if (b < 0) cout << "- " << -b / u << "i/" << c / u << "\n\n";
                else cout << b / u << "i/" << c / u << "\n\n";
            }
            else {
                if (b < 0)
                    cout << a / c << " - " << -b / u << "i/" << c / u << "\n\n";
                else if (b == 0)
                    cout << a / c << "/n/n";
                else
                    cout << a / c << " + " << b / u << "i/" << c / u << "\n\n";
            }
        }
        else if (b % c == 0) {
            int u = UCLN(a, c);

            if (a == 0) {
                if (b < 0) cout << "- " << -b / c << "i\n\n";
                else cout << b / c << "i\n\n";
            }
            else {
                if (b < 0)
                    cout << a / u << '/' << c / u << " - " << -b / c << "i\n\n";
                else if (b == 0)
                    cout << a / u << '/' << c / u << "\n\n";
                else
                    cout << a / u << '/' << c / u << " + " << b / c << "i\n\n";
            }
        }
        else {
            int u1 = UCLN(a, c);
            int u2 = UCLN(b, c);

            if (b < 0)
                cout << a / u1 << '/' << c / u1 << " - " << -b / u2 << "i/" << c / u2 << "\n\n";
            else if (b == 0)
                cout << a / u1 << '/' << c / u2 << "\n\n";
            else
                cout << a / u1 << '/' << c / u1 << " + " << b / u2 << "i/" << c / u2 << "\n\n";
        }
    }
}

int main() {
    srand((int)time(0));

    cout << "Nhap phan nguyen va phan ao cua z1: ";
    z1.nhap();
    //z1.xuat();
    cout << "Nhap phan nguyen va phan ao cua z2: ";
    z2.nhap();
    //z2.xuat();

    Tong();
    Hieu();
    Tich();
    Thuong();

    return 0;
}