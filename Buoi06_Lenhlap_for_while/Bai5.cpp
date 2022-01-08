#include <iostream>

using namespace std;

int main()
{
    int a, b;

    do
    {
        cout << "Nhập a, b nguyên dương: "; cin >> a >> b;
    } while (a <= 0 || b <= 0);

    if (a >= b)
    {
        for (int i = b; i > 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                cout << "Ước chung lớn nhất của " << a << " và " << b << " là " << i << endl;
                return 0;
            }
        }
        cout << "Ước chung lớn nhất của " << a << " và " << b << " là 1" << endl;
    }
    else
    {
        for (int i = a; i > 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                cout << "Ước chung lớn nhất của " << a << " và " << b << " là " << i << endl;
                return 0;
            }
        }
        cout << "Ước chung lớn nhất của " << a << " và " << b << " là 1" << endl;
    }

    return 0;
}