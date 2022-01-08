#include <iostream>

using namespace std;

int main()
{
    int n;
    float S = 0;

    do
    {
        cout << "Nhập số nguyên dương n: "; cin >> n;
    } while (n <= 0);

    for(float i = 1; i <= n; i++)
    {
        S += 1 / i;
    }

    cout << "S = " << S << endl;

    return 0;
}