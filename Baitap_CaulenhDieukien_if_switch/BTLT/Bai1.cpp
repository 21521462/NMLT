#include <iostream>

using namespace std;

void gocPhanTu(int a)
{
    if (a > 360 || a < -360)
    {
        a = a % 360;
    }

    if (a >= 0)
    {
        if (a < 90)
        {
            cout << "Số đo thuộc góc phần tư thứ I.\n";
        }

        else if (a < 180)
        {
            cout << "Số đo thuộc góc phần tư thứ II.\n";
        }
        
        else if (a < 270)
        {
            cout << "Số đo thuộc góc phần tư thứ III.\n";
        }
        
        else
        {
            cout << "Số đo thuộc góc phần tư thứ IV.\n";
        }
    }
    else
    {
        if (a >= -90)
        {
            cout << "Số đo thuộc góc phần tư thứ IV.\n";
        }

        else if (a >= -180)
        {
            cout << "Số đo thuộc góc phần tư thứ III.\n";
        }
        
        else if (a >= -270)
        {
            cout << "Số đo thuộc góc phần tư thứ II.\n";
        }
        
        else
        {
            cout << "Số đo thuộc góc phần tư thứ I.\n";
        }
    }
}

int main()
{
    int a;

    cout << "Nhập số đo góc: "; cin >> a;

    gocPhanTu(a);

    return 0;
}