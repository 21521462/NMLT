#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cout << "Enter n: "; cin >> n;

    if (n > 1)
    {
        int m = 0;

        for (int i = 1; i <= sqrt(n); i++ )
        {
            if (n % i == 0)
            {
                m++;
            }
        }

        if (m <= 1)
        {
            cout << "n is a prime number." << endl;
        }
        else
        {
            cout << "n is not a prime number." << endl;
        }
    }
    else
    {
        cout << "n is not a prime number." << endl;
    }

    return 0;
}