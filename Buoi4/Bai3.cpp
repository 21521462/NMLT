#include <iostream>

using namespace std;

void Max_Min(int a, int b, int c)
{
    int max = a, min = a;

    if (b > max)
    {
        max = b;

        if (c > max)
        {
            max = c;
            min = a;
        }
        else
        {
            if (a > c)
            {
                min = c;
            }
        }
    }
    else
    {
        min = b;

        if (c < min)
        {
            min = c;
            max = a;
        }
        else
        {
            if (a < c)
            {
                max = c;
            }
        }
    }
    cout << "So lon nhat la: " << max << endl;
    cout << "So nho nhat la: " << min << endl;
}

int main()
{
    int a, b, c;

    cout << "Nhap a, b, c: "; cin >> a >> b >> c;

    Max_Min(a, b, c);

    return 0;
}