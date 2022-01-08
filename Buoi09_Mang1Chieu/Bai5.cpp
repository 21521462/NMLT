#include <iostream>

using namespace std;

int a[20];
int n;

void nhapMang()
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}

int xoaPhanTu(int k)
{
    if (k < 0 || k >= n) return 0;
    
    else
    {
        for (int i = k; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }

        n--;

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
        return 1;
    }
}

int main()
{

    int k;

    cout << "Nhập số phần tử: "; cin >> n;
    cout << "Nhập chỉ số cần xoá: "; cin >> k;

    nhapMang();
    cout << xoaPhanTu(k);
}