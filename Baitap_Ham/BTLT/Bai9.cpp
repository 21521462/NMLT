#include <iostream>

using namespace std;

void xuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

bool Tang(int l, int r)
{
    return l > r;
}

bool Giam(int l, int r)
{
    return l < r;
}

bool amTangduongGiam(int l, int r)
{
    if (l < 0 && r >= 0)
    {
        return false;
    }

    if (l >= 0 && r < 0)
    {
        return true;
    }

    return abs(l) < abs(r);
}

void sapXep(int *a, int n, bool (*quyLuat)(int, int))
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (quyLuat(a[i], a[j]))
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

int main()
{
    int temp, n, a[n];

    cout << "Nhập số phần tử: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i + 1 << "]= ";
        cin >> a[i]; 
    }

    cout << "Mảng trước khi sắp xếp: "; xuatMang(a, n);

    sapXep(a, n, amTangduongGiam);

    cout << "Mảng sau khi sắp xếp: "; xuatMang(a, n);

    return 0;
}