#include <iostream>
#include <cmath>

using namespace std;

int a[20];

void nhapMang(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}

void xuatSNT(int n)
{
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        int m = 0;

        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0) m++;
        }

        if (m == 1 && a[i] != 1)
        {
            cout << a[i] << ' ';
            p++;
        }
    }

    if (p == 0)
    {
        cout << "Mảng không có số nguyên tố nào." << endl;
    }

    else
    {
        cout << "là các số nguyên tố có trong mảng." << endl;
    }
}

int main()
{
    int n;

    cout << "Nhập số phần tử: "; cin >> n;

    nhapMang(n);
    xuatSNT(n);

    return 0;
}