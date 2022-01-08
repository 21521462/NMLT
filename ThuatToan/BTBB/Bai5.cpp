#include <iostream>

using namespace std;

int main()
{
    int a, b, c, max;

    cout << "Enter a, b, c: "; cin >> a >> b >> c;
    
    max = a;

    if (max >= b)
    {
        if (max >= c)
        {
            cout << "The largest number is: " << max << endl;
        }
        else
        {
            cout << "The largest number is: " << c << endl;
        }
    }
    else
    {
        max = b;

        if (max >= c)
        {
            cout << "The largest number is: " << max << endl;
        }
        else
        {
            cout << "The largest number is: " << c << endl;
        }
    }

    return 0;
}