#include <iostream>

using namespace std;

int main()
{
    int n, a = 1, b = 0, temp = 0;

    cout << "Enter n: "; cin >> n;

    while (n > 0)
    {
        temp = a;
        a = a + b;
        b = temp;
        n--;
    }

    cout << "F(n) = " << b << endl;

    return 0;
}