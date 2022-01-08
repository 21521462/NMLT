#include <iostream>

using namespace std;

int main()
{
    int n;

    do
    {
        cout << "Nhap n co 3 chu so: "; cin >> n;
    }
    while (n < 100 || n > 999);

    cout << "Chu so hang tram: " << n / 100 << endl;
    cout << "Chu so hang chuc: " << (n / 10) % 10 << endl;
    cout << "Chu so hang don vi: " << n % 10 << endl;

    return 0;
}