#include <iostream>
#include <cmath>

using namespace std;

double S;

int a(int n)
{
    S = 0;

    for (int i = 1; i <= n; i++)
    {
        S += i;
    }

    return S;
}

int b(int n)
{
    S = 0;

    for (int i = 1; i <= n; i++)
    {
        S += pow(i, 2);
    }

    return S;
}

float c(int n)
{
    S = 0;

    for (int i = 1; i <= n; i++)
    {
        S += 1.0 / i;
    }

    return S;
}

int d(int n)
{
    S = 1;

    for (int i = 1; i <= n; i++)
    {
        S *= i;
    }

    return S;
}

long e(int n)
{
    S = 0;
    int s;

    for (int i = 1; i <= n; i++)
    {
        s = 1;

        for (int j = 1; j <= i; j++)
        {
            s *= j;
        }

        S += s;
    }

    return S;
}

int main()
{
    int n;

    do
    {
        cout << "Nhập số nguyên dương n: "; cin >> n;
    } while (n <= 0);
    
    cout << a(n) << endl;
    cout << b(n) << endl;
    cout << c(n) << endl;
    cout << d(n) << endl;
    cout << e(n) << endl;

    return 0;
}