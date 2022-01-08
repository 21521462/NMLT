#include <iostream>
#include <cmath>

using namespace std;

int a[20];

void xuatSoNguyenTo(int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = 0;

        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0) m++;
        }

        if (m == 1 && a[i] != 1) cout << a[i] << " ";
    }
}

void nhapMang(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];

        while (i > 0 && a[i - 1] >= a[i])
        {
            cout << "Hãy nhập lại." << endl;
            cout << "a[" << i << "] = "; cin >> a[i];
        }
    }
}

int main()
{
    int n;

    cout << "Nhập số phần tử: "; cin >> n;

    nhapMang(n);
    xuatSoNguyenTo(n);

    return 0;
}