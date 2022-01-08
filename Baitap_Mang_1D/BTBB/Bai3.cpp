#include <iostream>

using namespace std;

int a[20];

void nhapMang(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}

int xoaPhanTu(int k, int n)
{
    if (0 <= k && k < n)
    {
        for (int i = k; i < n; i++)
        {
            a[i] = a[i + 1];
        }

        n--;

        cout << "Mảng sau khi xoá: ";

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }

        cout << endl;

        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    int n, k;

    cout << "Nhập số phần tử: "; cin >> n;
    cout << "Nhập vị trí phần tử muốn xoá: "; cin >> k;

    nhapMang(n);
    cout << xoaPhanTu(k, n);

    return 0;
}