#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m = 0;

    do
    {
        cout << "Nhập số nguyên dương n (n > 1): "; cin >> n;
    } while (n <= 1);
    

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            m++;
        }
    }

    if (m > 1)
    {
        cout << "n không là số nguyên tố.\n";
    }

    else
    {
        cout << "n là số nguyên tố.\n";
    }

    return 0;
}