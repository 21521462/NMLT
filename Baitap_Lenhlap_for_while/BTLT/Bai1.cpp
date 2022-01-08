#include <iostream>

using namespace std;

int Armstrong(int i)
{
    int m = 0, S = 0;
    int n = i;

    while (n > 0)
    {
        n = n / 10;
        m++;
    }

    for (n = i; n > 0; n = n / 10)
    {
        int a = n % 10, s = 1;

        for (int j = 1; j <= m; j++)
        {
            s = s * a;
        }

        S = S + s;
    }

    return S;
}


int main()
{
    cout << "Các số Armstrong nhỏ hơn 1000: ";

    for (int i = 1; i < 1000; i++)
    {
        if (Armstrong(i) == i)
        {
            cout << i << " ";
        }
    }

    return 0;
}