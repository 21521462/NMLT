#include <iostream>
#include <cmath>

using namespace std;

void giaiPT_Bac2(float a, float b, float c)
{
    float delta = b*b - 4*a*c;

    if (delta < 0)
    {
        cout << "Phương trình vô nghiệm." << endl;
    }

    else if (delta == 0)
    {
        cout << "Phương trình có nghiệm kép x1 = x2 = " << -b/(2*a) << endl;
    }

    else
    {
        cout << "Phương trình có hai nghiệm phân biệt:" << endl;
        cout << "x1 = " << (-b + sqrt(delta))/(2*a) << endl;
        cout << "x2 = " << (-b - sqrt(delta))/(2*a) << endl;
    }
}

int main()
{
    float a, b, c;

    cout << "Nhập a, b, c: "; cin >> a >> b >> c;

    giaiPT_Bac2(a, b, c);

    return 0;
}