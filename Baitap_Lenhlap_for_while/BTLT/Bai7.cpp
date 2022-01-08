#include <iostream>

using namespace std;

int main()
{
    int n;
    int a = 1, b = 0, temp;

    cout << "Nhập n: "; cin >> n;
    cout << "Dãy Fibonacci: ";

    for (int i = 0; i < n; i++)
    {
        temp = a;
        a = a + b;
        b = temp;

        cout << b << " ";
    }

    return 0;
}