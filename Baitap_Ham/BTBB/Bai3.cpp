#include <iostream>
#include <cmath>

using namespace std;

float delta(float a, float b, float c)
{
    return b * b - 4 * a * c;
}

int main()
{
    int a, b, c;

    do
    {
        cout << "Nhập a, b, c (a khác 0): "; cin >> a >> b >> c;
    } while (!a);
    
    if (delta(a, b, c) < 0)
    {
        cout << "Phương trình vô nghiệm." << endl;
    }

    else if (delta(a, b, c) == 0)
    {
        cout << "Phương trình có nghiệm kép x1 = x2 = " << -b / (2 * a) << endl;
    }

    else
    {
        cout << "Phương trình có hai nghiệm phân biệt: " << endl;
        cout << "x1 = " << (-b + sqrt(delta(a, b, c))) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(delta(a, b, c))) / (2 * a) << endl;
    }
    
    return 0;
}