#include <iostream>
#include <cmath>
#define eps 0.0001

using namespace std;

int main()
{
    double S = 1, s;

    for (int i = 1;; i++)
    {
        s = pow(-1, i) / (2 * i + 1);

        if (abs(s) > eps)
        {
            S += s;
        }
        else
        {
            break;
        }
    }

    cout << "PI = " << S * 4 << endl;

    return 0;
}