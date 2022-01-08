#include <iostream>

using namespace std;

int a[20];

void lietKe(int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j] && i != j) m++;
        }

        if (m == 0) cout << a[i] << " ";
    }

    cout << endl;
}

void nhapMang(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}

int main()
{
    int n;

    cout << "Nhập số phần tử: "; cin >> n;

    nhapMang(n);
    lietKe(n);

    return 0;
}