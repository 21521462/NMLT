#include <iostream>

using namespace std;

int layNut(int n)
{
    int S = 0;

    while (n > 0)
    {
        S = S + n % 10;
        n = n / 10;
    }

    return S % 10;
    
}

int main()
{
    int n;

    cout << "Nhap so xe: "; cin >> n;

    while (n < 1000 || n > 9999)
    {
        cout << "Nhap so xe co 4 chu so: "; cin >> n;
    }

    cout << "So nut: " << layNut(n) << endl;

    return 0;
}