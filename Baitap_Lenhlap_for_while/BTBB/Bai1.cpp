#include <iostream>

using namespace std;

int main()
{
    float n, S = 0;

    cout << "Nhập n: "; cin >> n;

    while (n <= 0)
    {
        cout << "Nhập n > 0: "; cin >> n;
    }
    
    for (float i = 1; i <= n; i++)
    {
        S = S + 1/(2*i);
    }

    cout << "S = " << S << endl;

    return 0;
}