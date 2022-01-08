#include <iostream>

using namespace std;

int a[8];

bool Xet(int x2, int y2)
{
    for (int i = 1; i < x2; i++)
    {
        if (a[i] == y2 || abs(i - x2) == abs(a[i] - y2)) 
            return false;
    }

    return true;
}

void Xuat(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

void Gan(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (Xet(i, j))
        {
            a[i] = j;

            if (i == n)
            {
                Xuat(n);
            }
            Gan(i + 1, n);
        }
    }
}

int main()
{
    int n = 8;
    
    Gan(1, n);

    return 0;
}