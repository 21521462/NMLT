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
    int u;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            u = i;
            break;
        }
    }

    for (int i = u + 1; i < n; i++)
    {
        if (a[i] < 0 && a[i] > a[u])
            u = i;
    }

    if (a[u] < 0) return u;
    else return -1;
}

int main()
{
    int n;

    cout << "Nhập số phần tử: "; cin >> n;

    nhapMang(n);
    
    if (viTri(n) == -1)
    {
        cout << "Mảng không có phần tử âm." << endl;
    }

    else
    {
        cout << "Vị trí phần tử có giá trị âm lớn nhất: " << viTri(n) << endl;
    }

    return 0;
}