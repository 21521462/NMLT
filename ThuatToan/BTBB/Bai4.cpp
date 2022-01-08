#include <iostream>

using namespace std;

int main()
{
    int n, S = 0;

    cout << "Enter n: "; cin >> n;

    while (n > 0)
    {
        S = S + n % 10;
        n = n / 10;
    }
    cout << "Sum of digits of n: " << S << endl;

    return 0;
}