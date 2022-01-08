#include <iostream>

using namespace std;

int UCLN(int a, int b)
{
    for (int i = a >= b? b : a;; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
}

int BCNN(int a, int b)
{
    for (int i = a >= b? a : b;; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            return i;
        }
    }
}

int main()
{
    int a, b;

    do
    {
        cout << "Nhập hai số nguyên dương a, b: "; cin >> a >> b;
    } while (a <= 0 || b <= 0);

    cout << "Ước chung lớn nhất của " << a << " và " << b << " là: " << UCLN(a, b) << endl;
    cout << "Bội chung lớn nhất của " << a << " và " << b << " là: " << BCNN(a, b) << endl;

    return 0;
}