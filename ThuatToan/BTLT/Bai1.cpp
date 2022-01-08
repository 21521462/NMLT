#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cout << "Enter a, b: "; cin >> a >> b;

    if (a >= b)
    {
        for (int i = b; i > 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                cout << "The greatest common divisor of " << a << " and " << b << " is " << i << endl;
                return 0;
            }
        }
        cout << "The greatest common divisor of " << a << " and " << b << " is 1" << endl;
    }
    else
    {
        for (int i = a; i > 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                cout << "The greatest common divisor of " << a << " and " << b << " is " << i << endl;
                return 0;
            }
        }
        cout << "The greatest common divisor of " << a << " and " << b << " is 1" << endl;
    }

    return 0;
}