#include <iostream>
#include <cmath>

using namespace std;

float KC(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float KC2(float x1, float y1, float x2, float y2)
{
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}
int main()
{
    float a1, a2, b1, b2, c1, c2;

    cout << "Nhập toạ độ điểm A: "; cin >> a1 >> a2;
    cout << "Nhập toạ độ điểm B: "; cin >> b1 >> b2;
    cout << "Nhập toạ độ điểm C: "; cin >> c1 >> c2;

    float c = KC(a1, a2, b1, b2), C = KC2(a1, a2, b1, b2);
    float b = KC(a1, a2, c1, c2), B = KC2(a1, a2, c1, c2);
    float a = KC(b1, b2, c1, c2), A = KC2(b1, b2, c1, c2);

    if (a < b + c && b < a + c && c < a + b)
    {
        if (a == b && b == c) cout << "Đây là tam giác đều." << endl;
        else
        {
            if (A == B + C || B == A + C || C == A + B)
            {
                cout << "Đây là tam giác vuông." << endl;
            }
            if (a == b || a == c || b == c)
            {
                cout << "Đây là tam giác cân." << endl;
            }
            else
            {
                cout << "Đây là tam giác thường." << endl;
            }
        }
    }
    else cout << "Đây không là tam giác." << endl;

    return 0;
}