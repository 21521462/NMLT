#include <iostream>

using namespace std;

int Pascal(int i, int k)
{   
    if (k == 0 || i == k)
    {
        return 1;
    }

    else
    {
        return Pascal(i - 1, k - 1) + Pascal(i - 1, k);
    }
}

int main()
{
    int n, a[n][n];

    cout << "Nhập n: "; cin >> n;

    for (int i = 0; i <= n; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            cout << Pascal(i, k) << " ";
        }

        cout << endl;
    }

    return 0;
}