#include <iostream>

using namespace std;

int main()
{
    int n, p, a[20], m = 0;

    cout << "Nhập số nguyên n: "; cin >> n;

    p =  n;
    n = 0;

    for (int i = 1; p > 0; i++)
    {
        m++;
        a[i] = p % 10;
        p /= 10;
    }

    for (int i = 1; i <= m / 2; i++)
    {
        if (a[i] == a[m - i + 1])
        {
            n++;
        }
    }

    if (n == m / 2)
    {
        cout << "Đây là số đối xứng." << endl;
    }
    else
    {
        cout << "Đây không là số đối xứng." << endl;
    }

    return 0;
}