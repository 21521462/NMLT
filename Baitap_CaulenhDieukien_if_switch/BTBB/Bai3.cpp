#include <iostream>

using namespace std;

int tamGiac(float a, float b, float c)
{
    if (a < b + c && b < a + c && c < a + b)
    {
        cout << "a, b, c là độ dài ba cạnh của một tam giác." << endl;

        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
        {
            cout << "Đây là tam giác vuông." << endl;
            return 0;
        }
        
        else if (a*a > b*b + c*c || b*b > a*a + c*c || c*c > a*a + b*b)
        {
            cout << "Đây là tam giác tù." << endl;
            return 0;
        }

        else
        {
            cout << "Đây là tam giác nhọn." << endl;
        }
    }
    else
    {
        cout << "a, b, c không là độ dài ba cạnh của một tam giác." << endl;
    }

    return 0;
}


int main()
{
    float a, b, c;

    do 
    {
        cout << "Nhập ba số dương a, b, c: "; cin >> a >> b >> c;
    } while (a <= 0 || b <= 0 || c <= 0);

    tamGiac(a, b, c);

    return 0;
}