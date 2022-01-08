#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter n: "; cin >> n;
    cout << "The odd divisors of n are: ";

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && i % 2 != 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}