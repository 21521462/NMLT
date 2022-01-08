#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;

    cout << "Nhập N: "; cin >> N;

    if (N > 1)
    {
        for (int n = 2; n <= N; n++)
        {
            int m = 0;

            for (int i = 1; i <= sqrt(n); i++ )
            {
                if (n % i == 0)
                {
                    m++;
                }
            }

            if (m <= 1)
            {
                cout << n << " ";
            }
        }
    }
    else
    {
        cout << "Không có số nguyên tố nào." << endl;
    }

    return 0;
}