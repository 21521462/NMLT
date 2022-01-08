#include <iostream>

using namespace std;

void doiCoSo(int n, int m)
{
    if (n != 0)
    {
        doiCoSo(n / m, m);
        int a = n % m;

        if (a > 9)
        {
            switch (a)
            {
            case 10:
                cout << 'A';
                break;
            case 11:
                cout << 'B';
                break;
            case 12:
                cout << 'C';
                break;
            case 13:
                cout << 'D';
                break;
            case 14:
                cout << 'E';
                break;
            case 15:
                cout << 'F';
                break;
            default:
                break;
            }
        }

        else
        {
            cout << a;
        }
    }
}

int main()
{
    int n, m;

    cout << "Nhập số muốn đổi: "; cin >> n;
    do
    {
        cout << "Nhập cơ số cần chuyển sang: "; cin >> m;
    } while (m > 16);

    cout << "Số đã chuyển đổi: "; doiCoSo(n, m);

    return 0;
}