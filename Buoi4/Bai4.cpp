#include <iostream>

using namespace std;

void Tong_Hieu_ThoiGian(int n1, int n2)
{
    int T = n1 + n2;
    int H = abs(n1 - n2);

    cout << "Tong 2 gio la: " << T/3600 << "h " << T%3600 / 60 << "m " << T%3600 % 60 << "s" << endl;
    cout << "Hieu 2 gio la: " << H/3600 << "h " << H%3600 / 60 << "m " << H%3600 % 60 << "s" << endl;
}

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;

    cout << "Nhap gio phut giay thu nhat: "; cin >> h1 >> m1 >> s1;
    cout << "Nhap gio phut giay thu hai: "; cin >> h2 >> m2 >> s2;

    int n1 = h1*3600 + m1*60 + s1;
    int n2 = h2*3600 + m2*60 + s2;

    Tong_Hieu_ThoiGian(n1, n2);

    return 0; 
}