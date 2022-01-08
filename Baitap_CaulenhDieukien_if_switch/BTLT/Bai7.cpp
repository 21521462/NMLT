#include <iostream>

using namespace std;

int main()
{
    float a, b, c, d, e, f;

    cout << "Nhập hệ: ";
    cin >> a >> b >> c >> d >> e >> f;

    if (e - d * b / a == 0)
    {
        if (f - d * c / a == 0)
        {
            cout << "Hệ vô số nghiệm.\n";
        }

        else
        {
            cout << "Hệ vô nghiệm.\n";
        }
    }

    else
    {
        float y = (f -  d * c / a) / (e - d * b / a);
        float x = (c - b * y) / a;

        cout << "Hệ có nghiệm duy nhất: ";
        cout << "{x, y} = {" << x << ", " << y << "}.\n";
    }
    
    return 0;
}