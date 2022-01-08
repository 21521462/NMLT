#include <iostream>

using namespace std;

int C(float n, float k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }

    else if (k > n)
    {
        return 0;
    }
    
    else if (0 < k && k < n)
    {
        return C(n - 1, k) + C(n - 1, k - 1);
    }

    return 0;
}

int main()
{
    int n, k;

    cout << "Nhập n, k: "; cin >> n >> k;
    cout << "C(" << n << ',' << k << ") = " << C(n, k) << endl;

    return 0;
}