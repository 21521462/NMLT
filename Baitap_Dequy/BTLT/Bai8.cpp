#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n < 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int giaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}

int S(int n)
{
    int S = 0;

    for (int i = 1; i <= n; i++)
    {
        S += giaiThua(i);
    }
    
    return S;
}

int C(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else if (k > n)
        return 0;
    else
        return C(n - 1, k) + C(n - 1, k - 1);
}

int main()
{
    int n, k;

    do
    {
        cout << "Nhập n, k: "; cin >> n >> k;
    } while (k < 0);
    
    cout << "Số fibonacci thứ " << n << " là " << fibonacci(n) << endl;
    cout << "Tổng S = " << S(n) << endl;
    cout << "C(" << n << ", " << k << ") = " << C(n, k) << endl;

    return 0;
}