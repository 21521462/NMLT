#include <iostream>

using namespace std;

int main()
{
    int n, max;

    cout << "Enter n: "; cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }

    max = a[0];

    for (int j = 1; j < n; j++)
    {
        if (max < a[j])
        {
            max = a[j];
        }
    }

    cout << "The largest number is " << max << endl;

    return 0;
}