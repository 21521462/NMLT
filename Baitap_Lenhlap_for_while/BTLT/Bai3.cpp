#include <iostream>

using namespace std;

int Le(int n)
{
    int S = 1;

    for (int i = 3; i <= n; i += 2)
    {
        S = S * i;
    }

    return S;
}

int Chan(int n)
{
    int S = 1;

    for (int i = 2; i <= n; i += 2)
    {
        S = S * i;
    }

    return S;
}

int main()
{
    int n;

    do
    {
        cout << "Nhập n nguyên dương: "; cin >> n;
    } while (n <= 0);

    cout << "n!! = ";

    if (n % 2 == 0)
    {
        cout << Chan(n);
    }
    
    else 
    {
        cout << Le(n);
    }

    cout << '\n';

    return 0;
}