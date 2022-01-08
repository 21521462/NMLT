#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

void tamGiac()
{
    float a, b, c;
    float p = (a + b + c) / 2;

    cout << "Nhập độ dài 3 cạnh: "; cin >> a >> b >> c;
    cout << "Chu vi: " << p * 2 << '\n';
    cout << "Diện tích: " << sqrt(p * (p - a) * (p - b) * (p - c)) << '\n';
}

void duongTron()
{
    float r;

    cout << "Nhập bán kính: "; cin >> r;
    cout << "Chu vi: " << 2 * M_PI * r << '\n';
    cout << "Diện tích: " << M_PI * r * r << '\n';
}

void hinhChuNhat()
{
    float a, b;

    cout << "Nhập chiều dài, chiều rộng: "; cin >> a >> b;
    cout << "Chu vi: " << 2 * (a + b) << '\n';
    cout << "Diện tích: " << a * b << '\n';
}

int main()
{
    int n;

    cout << "Chương trình tính chu vi, diện tích\n";
    cout << "1. Tam giác\n";
    cout << "2. Đường tròn\n";
    cout << "3. Hình chữ nhật\n";
    cout << "Chọn hình bạn muốn tính toán: "; cin >> n;

    switch (n)
    {
    case 1:
        tamGiac();
        break;
    case 2:
        duongTron();
        break;
    case 3:
        hinhChuNhat();
        break;
    default:
        break;
    }

    return 0;
}