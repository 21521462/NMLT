#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

int a[MAX], na;

int randInt(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

int nhapMang()
{
    srand((int)time(0));

    do
    {
        cout << "    Nhập số phần tử: "; cin >> na;
    } while (na <= 0);

    cout << "    Mảng vừa nhập: ";

    for (int i = 0; i < na; i++)
    {
        a[i] = randInt(-10, 10);
        cout << a[i] << " ";
    }
    
    cout << endl;
    return 0;
}

int op38()
{
    int dem = 0;

    for (int i = 0; i < na; i++)
    {
        if (abs(a[i]) % 2 == 0 && a[i] % 4 != 0)
            dem++;
    }

    cout << "38. Số phần tử chia hết cho 2 nhưng không chia hết cho 4: " << dem << endl;
    return 0;
}

bool kiemTraSNT(int ai)
{
    if (ai <= 1) return false;
    else
    {
        for (int i = 2; i * i <= ai; i++)
        {
            if (ai % i == 0) return false;
        }

        return true;
    }
}

int op39()
{
    int S = 0;

    for (int i = 0; i < na; i++)
    {
        if (kiemTraSNT(a[i]))
            S += a[i];
    }

    cout << "39. Tổng các số nguyên tố: " << S << endl;
    return 0;
}

int op40()
{
    int Sc = 0, Sl = 0;

    for (int i = 0; i < na; i++)
    {
        if (a[i] % 2 == 0) Sc += a[i];
        else Sl += a[i];
    }

    cout << "40. Tổng các phần tử chẵn: " << Sc << endl;
    cout << "    Tổng các phần tử lẻ: " <<  Sl << endl;
    return 0;
}

int op41()
{
    int S = 0;

    for (int i = 0; i < na; i += 2)
    {
        S += a[i];
    }

    cout << "41. Tổng các phẩn tử ở vị trí chẵn: " << S << endl;
    return 0;
}

int op42()
{
    int S = 0;
    
    for (int i = 1; i < na - 1; i++)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
            S += a[i];
    }

    cout << "42. Tổng các phần tử cực đại: " << S << endl;
    return 0;
}

int op43()
{
    int S = 0;

    for (int i = 1; i < na - 1; i++)
    {
        if (a[i - 1] > a[i] && a[i] < a[i + 1])
            S += a[i];
    }

    cout << "43. Tổng các phần tử cực tiểu: " << S << endl;
    return 0;
}

int op44()
{
    int S = 0;

    for (int i = 1; i < na - 1; i++)
    {
        if (a[i] == a[i + 1] + a[i - 1])
            S += a[i];
    }

    cout << "44. Tổng các phần tử xung quanh: " << S << endl;
    return 0;
}

int main()
{
    cout << setw(12) << " " << "CÁC THAO TÁC TÍNH TOÁN\n";
    cout << setfill('-');
    cout << setw(46) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "38. Đếm các phần tử chia hết cho 2 nhưng không\n    chia hết cho 4\n";
    cout << "39. Tính tổng các số nguyên tố có trong mảng\n";
    cout << "40. Tính tổng các số chẵn/lẻ trong mảng\n";
    cout << "41. Tính tổng các phần tử ở vị trí chẵn\n";
    cout << "42. Tính tổng các phần tử cực đại\n";
    cout << "43. Tính tổng các phần tử cực tiểu\n";
    cout << "44. Tính tổng các phần tử xung quanh\n";
    cout << setw(46) << "-" << endl;

    nhapMang();
    op38();
    op39();
    op40();
    op41();
    op42();
    op43();
    op44();

    return 0;
}