#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int S = 0, n;
    
    cout << "Nhập số nhị phân: ";
    cin >> n;

    for (int i = 0; n > 0; i++)
    {
        cout << (n % 10)  * pow(2, i) << endl;
        S += (n % 10) * pow(2, i);
        n = n / 10;
    }

    cout << "Số thập phân tương ứng: " << S << endl;

    return 0;
}