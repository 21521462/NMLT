#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

#define MAX 100

int a[MAX], na, nb;
float b[MAX];

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

    for (int i = 0; i< na; i++)
    {
        a[i] = randInt(-5, 5);
    }

    do
    {
        cout << "Nhập số phần tử cho mảng số thực: ";
        cin >> nb;
    } while (nb <= 0);

    for (int i = 0; i < nb; i++)
    {
        b[i] = randFloat(-5, 5);
        //cout << "b[" << i << "] = "; cin >> b[i];
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

int op15()
{
    for (int i = 0; i < nb; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (b[i] < b[j]) swap(b[i], b[j]);
        }
    }

    cout << "15. Mảng sau khi sắp xếp: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

bool kiemTra_op16(int ai, int aj)
{
    if (abs(ai) % 2 == 0 && (aj) % 2 == 0 && ai < aj)
        return true;
    return false;
}

int op16()
{
    for (int i = 0; i < na; i++)
    {
        for (int j = i + 1; j < na; j++)
        {
            if (kiemTra_op16(a[i], a[j])) swap(a[i], a[j]);
        }
    }

    cout << "16. Mảng sau khi sắp xếp: ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }
    
    cout << endl;
    return 0;
}

int op17()
{
    for (int i = 0; i < nb; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (b[i] > 0 && b[j] < 0) swap(b[i], b[j]);
        }
    }

    cout << "17. Mảng sau khi sắp xếp: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

bool kiemTra_op18(float bi, float bj)
{
    if (bi == 0) return true;
    if (bi < 0 && bj > 0) return true;
    if (bi > 0 && bj < 0) return false;

    return abs(bi) < abs(bj);
}

int op18()
{
    for (int i = 0; i < nb; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (kiemTra_op18(b[i], b[j])) swap(b[i], b[j]);
        }
    }

    cout << "18. Mảng sau khi sắp xếp: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int main()
{
    cout << setw(14) << " " << "CÁC THAO TÁC SẮP XẾP\n";
    cout << setfill('-');
    cout << setw(48) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "15. Sắp xếp mảng theo thứ tự giảm dần.\n";
    cout << "16. Sắp xếp các phần tử chẵn giảm dần.\n";
    cout << "17. Sắp xếp các phần tử âm dương trong mảng.\n";
    cout << "18. Sắp xếp mảng sao cho các số dương đứng\nđầu mảng giảm dần, kế đến là các số âm tăng dần,\ncuối cùng là các số 0.\n";
    cout << "(Mục 16 sẽ thực hiên trên mảng số nguyên).\n";
    cout << setw(48) << "-" << endl;

    nhapMang();
    op15();
    op16();
    op17();
    op18();

    return 0;
}