#include <iostream>

using namespace std;

int main()
{
    int y;

    cout << "Nhập năm: "; cin >> y;

    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    {
        cout << "Đây là năm nhuận.\n";
    }

    else
    {
        cout << "Đây không là năm nhuận.\n";
    }

    return 0;
}