#include <iostream>

using namespace std;

int main()
{
    int temp, n;
    char a[n];

    cout << "Nhập số phần tử: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Mảng trước khi sắp xếp: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    cout << endl;
    cout << "Mảng sau khi sắp xếp: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}