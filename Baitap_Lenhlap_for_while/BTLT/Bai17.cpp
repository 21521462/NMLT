#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m = 0;

    cout << "Nhập số thập phân: "; cin >> n;

    for (int i = 0; n >= pow(2, i); i++)
    {
        m++;
    }

    cout << "Số nhị phân tương ứng: ";

    for (int i = m - 1; i >= 0; i--)
    {
        if (n >= pow(2, i))
        {
            cout << 1;
            n -= pow(2, i);
        }
        else
        {
            cout << 0;
        }
    }

    return 0;
}