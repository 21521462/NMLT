#include <iostream>
#include <cmath>

using namespace std;

long hamGiaiThua(int i)
{
    if (i == 1)
    {
        return 1;
    }

    return i * hamGiaiThua(i - 1);
}

int main()
{
    float c, x;
    double S = 1, s;

    cout << "Nhập x: "; cin >> x;

    do
    {
        cout << "Nhập c (c > 0): "; cin >> c;
    } while (c <= 0);
    
    for (int i = 1;; i++)
    {
        s = pow(x, i) / hamGiaiThua(i);

        if (abs(s) > c)
        {
            S += s;
        }
        else
        {
            break;
        }
    }

    cout << "e^(" << x << ") = " << S << endl;

    return 0;
}