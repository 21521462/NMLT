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

void viTri(int n)
{
    int m = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < 0)
        {
            m = i;
            break;
        }
    }

    for (int i = m + 1; i < n - 1; i++)
    {
        if (a[i] < 0 && a[i] > a[m]) m = i;
    }

    if (a[m] < 0) cout << "Vị trí giá trị âm lớn nhất: " << m << endl;
    else cout << "Không có giá trị âm trong mảng." << endl;
}

int main()
{
    int n;

    cout << "Nhập số phần tử: "; cin >> n;

    nhapMang(n);
    viTri(n);

    return 0;
}