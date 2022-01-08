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

void kiemTra(int n)
{
    int m = 0;

    for (int i = 0; i < 10 / 2; i++)
    {
        if (a[i] == a[10 - 1 -i]) m++;
    }

    if (m == 10 / 2)
    {
        cout << "Đây là mảng đối xứng." << endl;
    }

    else
    {
        cout << "Đây là mảng không đối xứng." << endl;
    }
}

int main()
{
    int n;

    cout << "Nhập số phần tử: "; cin >> n;

    nhapMang(n);
    kiemTra(n);

    return 0;
}