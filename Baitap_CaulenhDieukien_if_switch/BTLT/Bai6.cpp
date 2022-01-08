#include <iostream>

using namespace std;

float tienTaxi(float km)
{
    if (km <= 1)
    {
        return km * 5000; 
    }

    else if (km <= 31)
    {
        return 5000 + (km - 1) * 4000;
    }
    
    else
    {
        return 5000 + 30 * 4000 + (km -31) * 3000;
    }
}

int main()
{
    float km;

    do
    {
        cout << "Nhập số km: "; cin >> km;
    } while (km < 0);
    
    cout << "số tiền phải trả: " << tienTaxi(km) << " đồng.\n";

    return 0;
}