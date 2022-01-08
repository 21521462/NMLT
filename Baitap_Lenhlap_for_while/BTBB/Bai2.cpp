#include <iostream>

using namespace std;

int main()
{
    int n, S = 0;

    cout << "Nhập n: "; cin >> n;

    while (n < 0)
    {
        cout << "Nhập n >= 0: "; cin >> n;
    }

    for (int i = 1; i <= n; i++)
    {
        int s = 1;
        
        for (int j = 1; j <= i; j++)
        {
            s = s*j;
        }
        S = S + s;
    }

    cout << "S = " << S << endl;

    return 0;
}