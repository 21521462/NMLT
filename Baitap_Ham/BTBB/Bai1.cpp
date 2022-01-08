#include <iostream>
#include <cmath>

using namespace std;

int S(int n)
{
    int m, S = 0;

    for (int i = 2; i <= n; i++)
    {
        m = 0;
        
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                m++;
            }
        }

        if (m <= 1)
        {
            S += i;
        }
    }

    return S;
}

int main()
{
    int n;

    do
    {
        cout << "Nhập số nguyên dương n: "; cin >> n;
    } while (n <= 0);

    cout << "Tổng các số nguyên tố nhỏ hơn " << n << " là: " << S(n);

    return 0;
}