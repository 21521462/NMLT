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

int viTri(int n)
{
    int u = a[0], v = 0;

    for (int i = 1; i < n; i++)
    {
        if (u <= a[i])
        {
            u = a[i];
            v = i;
        }
    }

    return v;
}

int main()
{
    int n;

    cout << "Nhập số phần tử: "; cin >> n;

    nhapMang(n);
    
    cout << "Vị trí phần tử lớn nhất: " << viTri(n) << endl;

    return 0;
}