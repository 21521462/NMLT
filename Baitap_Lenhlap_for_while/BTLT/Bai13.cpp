#include <iostream>

using namespace std;

int giaiThua(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * giaiThua(n - 1);
}

int main()
{
    int n;

    do
    {
        cout << "Nhập n: "; cin >> n;
    } while (n < 0);
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << giaiThua(i) / (giaiThua(j) * giaiThua(i - j)) << " ";
        }

        cout << endl;
    }
}