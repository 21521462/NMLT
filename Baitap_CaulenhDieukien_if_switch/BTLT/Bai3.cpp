#include <iostream>

using namespace std;

void GTLN(float a, float b, float c, float d)
{
    float max = a;

    if (max < b)
    {
        max = b;

        if (max < c)
        {
            max = c;

            if (max < d)
            {
                max = d;
            }
        }
    }
    
    if (max < c)
    {
        max = c;

        if (max < d)
        {
            max = d;
        }
    }

    if (max < d)
    {
        max = d;
    }

    cout << "Giá trị lớn nhất: " << max << endl;
}

int main()
{
    float a, b, c, d;

    cout << "Nhập a, b, c, d: "; cin >> a >> b >> c >> d;

    GTLN(a, b, c, d);

    return 0;
}