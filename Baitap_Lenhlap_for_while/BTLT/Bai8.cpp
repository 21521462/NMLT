#include <iostream>
#include <cmath>
#define eps 0.0001

using namespace std;

long hamGiaiThua(int n)
{
    long s = 1;

    for (int i = 1; i <= 2 * n + 1; i++)
    {
        s *= i;
    }

    return s;
}

int main()
{
    float x;
    long double s = eps + 1, S = 0;

    cout << "Nhập x: "; cin >> x;

    for (int i = 0;; i++)
    {
        s = pow(-1, i) * pow(x, 2 * i + 1) / hamGiaiThua(i);
        
        if (abs(s) > eps)
        {
            S += s;
        }
        else
        {
            break;
        }
    }

    cout << "sin(" << x << ") = " << S << endl;
    
    return 0;
}