#include <iostream>

using namespace std;

int giaiThua(int i)
{
    if (i == 1)
    {
        return 1;
    }
    else
    {
        return i * giaiThua(i - 1);
    }
}

int main()
{
    int n, S = 0;

    cout << "Nhập n: "; cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        S += giaiThua(i);
    }

    cout << "S = " << S << endl;
    
    return 0;
}