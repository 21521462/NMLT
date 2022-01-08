#include <iostream>

using namespace std;

int main()
{
    cout << "Các số hoàn hảo nhỏ hơn 5000: ";

    for (int i = 1; i < 5000; i++)
    {
        int S = 0;

        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
            S = S + j;
            }
        }

        if (S == i)
        {
            cout << i << " ";
        }
    }

    return 0;
}