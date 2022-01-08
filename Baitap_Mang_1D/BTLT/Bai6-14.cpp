#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX 100

int a[MAX], na, nb;
float b[MAX], x;

int randInt(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

float randFloat(float minN, float maxN)
{
    float scale = rand() / (float)RAND_MAX;
    return roundf((minN + scale * (maxN - minN)) * 100) / 100;
}

int nhapMang()
{
    srand((int)time(0));

    do
    {
        cout << "Nhập số phần tử cho mảng số nguyên: ";
        cin >> na;
    } while (na <= 0);

    for (int i = 0; i < na; i++)
    {
        //cout << "a[" << i << "] = "; cin >> a[i];
        a[i] = randInt(-5, 5);
    }

    do
    {
        cout << "Nhập số phần tử cho mảng số thực: ";
        cin >> nb;
    } while (nb <= 0);

    for (int i = 0; i < nb; i++)
    {
        //cout << "b[" << i << "] = "; cin >> b[i];
        b[i] = randFloat(-5, 5);
    }

    cout << "Mảng số nguyên vừa nhập: ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    cout << "Mảng số thực vừa nhập: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op6(float &x)
{
    cout << "6. Nhập giá trị muốn tìm kiếm: "; cin >> x;

    for (int i = nb - 1; i >= 0; i--)
    {
        if (b[i] == x)
        {
            cout << "6. Vị trí cuối cùng của phần tử có giá trị bằng " << x << ": " << i << endl;
            return 0;
        }
    }

    cout << "6. Không tìm thấy." << endl;
    return 0;
}

bool kiemTra_op7(int m)
{
    int dem = 0;

    for (int i = 1; i <= sqrt(m); i++)
    {
        if (m % i == 0) dem ++;
    }

    if (m != 1 && dem == 1)
        return true;
    else
        return false;
}

int op7()
{
    for (int i = 0; i < na; i++)
    {
        if(kiemTra_op7(a[i]))
        {
            cout << "7. Vị trí số nguyên tố đầu tiên: " << i << endl;
            return 0;
        }
    }

    cout << "7. Mảng không có số nguyên tố." << endl;
    return 0;
}

int op8()
{
    float m = b[0];

    for (int i = 1; i < nb; i++)
    {
        if (m > b[i]) m = b[i];
    }

    cout << "8. Số nhỏ nhất trong mảng: " << m << endl;
    return 0;
}

int op9()
{
    float m = b[0];

    for (int i = 1; i < nb; i++)
    {
        if (m < b[i]) m = b[i];
    }

    cout << "9. Số lớn nhất trong mảng: " << m << endl;
    return 0;
}

int op10()
{
    float max = 0, min;

    for (int i = 1; i < nb; i++)
    {
        if (max < b[i]) max = b[i];
    }

    min = max;

    for (int i = 0; i < nb; i++)
    {
        if (min > b[i] && b[i] > 0) min = b[i];
    }

    if (max > 0 && min > 0)
    {
        cout << "10. Số dương lớn nhất: " << max << endl;
        cout << "10. Số dương nhỏ nhất: " << min << endl;
        return 0;
    }
    else
    {
        cout << "10. Mảng không có số dương." << endl;
        return 0;
    }
}

int op11(float &x)
{
    cout << "11. Nhập giá trị muốn tìm kiếm: "; cin >> x;

    for (int i = nb - 1; i >= 0; i--)
    {
        if (b[i] == x)
        {
            cout << "11. Vị trí cuối cùng của phần tử có giá trị bằng " << x << ": " << i << endl;
            return 0;
        }
    }

    cout << "11. Không tìm thấy." << endl;
    return 0;
}

int op12()
{
    float min = b[0];
    int c[MAX], y = 0;

    for (int i = 1; i < nb; i++)
    {
        if (min > b[i])
            min = b[i];
    }

    for (int i = 0; i < nb; i++)
    {
        if (b[i] == min)
        {
            c[y] = i;
            y++;
        }
    }

    cout << "12. Vị trí phần tử nhỏ nhất trong mảng: ";

    for (int i = 0; i < y; i++)
    {
        cout << c[i] << " ";
    }

    cout << endl;
    return 0;
}

int op13()
{
    float max = b[0];
    int c[MAX], y = 0;

    for (int i = 1; i < nb; i++)
    {
        if (max < b[i])
            max = b[i];
    }

    for (int i = 0; i < nb; i++)
    {
        if (b[i] ==  max)
        {
            c[y] = i;
            y++;
        }
    }

    cout << "13. Vị trí phần tử lớn nhất trong mảng: ";
    
    for (int i = 0; i < y; i++)
    {
        cout << c[i] << " ";
    }

    cout << endl;
    return 0;
}

bool chuaIn(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[n]) return false;
    }

    return true;
}

int op14()
{
    int dem, max, c[MAX];

    for (int i = 0; i < na; i++)
    {
        dem = 0;

        for (int j = 0; j < na; j++)
        {
            if (a[i] == a[j]) dem++;
        }

        c[i] = dem;
    }

    max = c[0];

    for (int i = 1; i < na; i++)
    {
        if (max < c[i]) max = c[i];
    }

    cout << "14. Phần tử xuất hiện nhiều nhất: ";
    
    for (int i = 0; i < nb; i++)
    {
        if (c[i] == max && chuaIn(i))
            cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

int main()
{
    cout << setw(21) << " " << "CÁC THAO TÁC TÌM KIẾM" << endl;
    cout << setfill('-');
    cout << setw(63) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau: " << endl;
    cout << "6. Vị trí cuối cùng của phần tử x trong mảng." << endl;
    cout << "7. Vị trí số nguyên tố đầu tiên trong mảng nếu có." << endl;
    cout << "8. Số nhỏ nhất trong mảng." << endl;
    cout << "9. Số lớn nhất trong mảng." << endl;
    cout << "10. Số dương nhỏ nhất/lớn nhất trong mảng." << endl;
    cout << "11. Vị trí phần tử có giá trị x xuất hiện cuối cùng trong mảng." << endl;
    cout << "12. Vị trí của phần tử nhỏ nhất trong mảng 1 chiều." << endl;
    cout << "13. Vị trí của phần tử lớn nhất trong mảng 1 chiều." << endl;
    cout << "14. Phần tử xuất hiện nhiều nhất trong mảng số nguyên." << endl;
    cout << "(Mục 7, 14 sẽ thực hiện trên mảng số nguyên)." << endl;
    cout << setw(63) << "-" << endl;

    nhapMang();

    op6(x);
    op7();
    op8();
    op9();
    op10();
    op11(x);
    op12();
    op13();
    op14();

    return 0;
}