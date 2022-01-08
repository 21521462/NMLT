#include <iostream>
#include <cmath>

using namespace std;

long hamGiaiThua(int n)
{
    long s = 1;

    for (int i = 1; i <= 2 * n; i++)
    {
        s *= i;
    }

    return s;
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
        s = pow(-1, i) * pow(x, 2 * i) / hamGiaiThua(i);
        
        if (abs(s) > c)
        {
            S += s;
        }
        else
        {
            break;
        }
    }

    cout << "cos(" << x << ") = " << S << endl;

    return 0;
}