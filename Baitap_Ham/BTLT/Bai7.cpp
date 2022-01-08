#include <iostream>

using namespace std;

void Tong(int n)
{
    float a[n], S = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];

        S += a[i];
    }

    cout << "Tổng các số: " << S << endl;
}

int main()
{
    int n;

    cout << "Nhập số lượng số: "; cin >> n;

    Tong(n);

    return 0;
}