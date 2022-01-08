#include <iostream>

using namespace std;

int main()
{
    int N, S = 0;

    cout << "Enter N: "; cin >> N;

    for (int i = 1; i < N; i++)
    {
        if (N % i == 0)
        {
            S = S + i;
        }
    }

    if (S == N)
    {
        cout << N << " is a perfect number." << endl;
    }
    else
    {
        cout << N << " is not a perfect number." << endl;
    }

    return 0;
}