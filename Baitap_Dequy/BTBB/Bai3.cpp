#include <iostream>

using namespace std;

int UCLN(int x, int y)
{
    if (x == y)
    {
        return x;
    }

    else if (x > y)
    {
        return UCLN(x - y, y);
    }

    else
    {
        return UCLN(x, y - x);
    }
}

int main()
{
    int x, y;

    do
    {
        cout << "Nhập x, y: "; cin >> x >> y;
    } while (x <= 0 || y <= 0);
    
    cout << "Ước chung lớn nhất: " << UCLN(x, y) << endl;

    return 0;
}