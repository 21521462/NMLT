#include <iostream>

using namespace std;

float tienTaxi(float d)
{
    float t;

    if (d <= 1)
    {
        t = 15000*d;
    }

    else if (d <= 5)
    {
        t = 15000 + (d- 1)*13500;
    }

    else if (d <= 120)
    {
        t = 15000 + 4*13500 + (d-5)*11000;
    }
    
    else
    {
        t = (15000 + 4*13500 + (d-5)*11000) * 0.9;
    }

    return t;
}

int main()
{
    float d;

    cout << "Nhập số km: "; cin >> d;
    cout << "Số tiền taxi phải trả: " << tienTaxi(d) << endl;

    return 0;
}