#include <iostream>

using namespace std;

int main()
{
    int n;

    do
    {
        cout << "Nhập số nguyên dương n: "; cin >> n;
    } while (n <= 0);
    
    while (n > 0)
    {
        cout << n % 10;
        n = n / 10;
    }

    return 0;
}