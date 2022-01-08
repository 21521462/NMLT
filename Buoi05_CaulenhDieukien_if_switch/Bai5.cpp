#include <iostream>

using namespace std;

void namNhuan(int m)
{
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "Tháng có 31 ngày." << endl;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        cout << "Tháng có 30 ngày." << endl;
        break;

    case 2:
        cout << "Tháng có 29 ngày." << endl;
        break;

    default:
        break;
    }
}

void namKhongNhuan(int m)
{
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "Tháng có 31 ngày." << endl;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        cout << "Tháng có 30 ngày." << endl;
        break;

    case 2:
        cout << "Tháng có 28 ngày." << endl;
        break;

    default:
        break;
    }
}

int main()
{
    int m, y;

    do
    {
        cout << "Nhập tháng, năm: "; cin >> m >> y;
    } while (m < 1 || m > 12 || y <= 1975);

    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    {
        namNhuan(m);
    }
    else
    {
        namKhongNhuan(m);
    }

    return 0;
}