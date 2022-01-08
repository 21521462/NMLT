#include <iostream>

using namespace std;

int main()
{
    int n;
    long int S = 1;

    do
    {
        cout << "Nhập n nguyên dương: "; cin >> n;
    } while (n <= 0);
    
    for (int i = 2; i <= n; i++)
    {
        S = S*i;
    }

    cout << "Giai thừa của n: " << S << endl;

    return 0;
}