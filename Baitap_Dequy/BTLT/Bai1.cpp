#include <iostream>

using namespace std;

int giaiThua(int n)
{
    if (n == 1)
    {
        return 1;
    }

    else
    {
        return n * giaiThua(n - 1);
    }
}

int main()
{
    int n;

    cout << "Nhập n: "; cin >> n;
    cout << "Giai thừa của " << n << " : " << giaiThua(n) << endl;

    return 0;
}