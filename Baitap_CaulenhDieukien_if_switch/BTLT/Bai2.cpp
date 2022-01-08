#include <iostream>

using namespace std;

int main()
{
    float a, b;

    cout << "Nhập a, b: "; cin >> a >> b;

    float max = a;

    if (a < b)
    {
        max = b;
    }

    cout << "Giá trị lớn nhất là: " << max << endl;

    return 0;
}