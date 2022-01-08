#include <iostream>

using namespace std;

void Tong(int n)
{
    int a[n], S = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];

        S += a[i];
    }

    cout << "Tổng các số nguyên: " << S << endl;
}

int main()
{
    int n;

    cout << "Nhập số số nguyên: "; cin >> n;
    Tong(n);

    return 0;
}