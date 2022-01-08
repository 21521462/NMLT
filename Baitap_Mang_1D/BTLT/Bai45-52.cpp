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
        a[i] = randInt(-5, 5);
        cout << a[i] << " ";
    }

    return 0;
}

bool kiemTraSNT(int ai)
{
    if (ai <= 1) return false;
    else
    {
        for (int i = 2; i * i <= ai; i++)
        {
            if (ai % 2 == 0) return false;
        }

        return true;
    }
}

int op45()
{
    int b[MAX], nb = 0;

    for (int i = 0; i < na; i++)
    {
        if (kiemTraSNT(a[i]))
        {
            b[nb] = a[i];
            nb++;
        }
    }

    cout << endl << "45. Mảng b (chứa các số nguyên tố): ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}

int op46()
{
    int b[MAX], nb = 0, c[MAX], nc = 0;

    for (int i = 0; i < na; i++)
    {
        if (a[i] > 0)
        {
            b[nb] = a[i];
            nb++;
        }
        else
        {
            c[nc] = a[i];
            nc++;
        }
    }

    cout << endl << "46. Mảng b (chứa các số nguyên dương): ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl << "    Mảng c (chứa các số còn lại): ";

    for (int i = 0; i < nc; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}

int op47()
{
    int b[MAX], nb = 0, c[MAX], nc = 0;

    for (int i = 0; i < na; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[nb] = a[i];
            nb++;
        }
        else
        {
            c[nc] = a[i];
            nc++;
        }
    }

    cout << endl << "47. Mảng gồm các số chẵn: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl << "    Mảng gồm các số lẻ: ";

    for (int i = 0; i < nc; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}

int op48()
{
    int b[MAX], nb;

    srand((int)time(0));

    do
    {
        cout << endl << "48. Nhập số phần tử cho mảng nối: "; cin >> nb;
    } while (nb <= 0);

    cout << "    Mảng vừa nhập: ";

    for (int i = 0; i < nb; i++)
    {
        b[i] = randInt(-5, 5);
        cout << b[i] << " ";
    }

    na += nb;

    for (int i = na - nb; i < na; i++)
    {
        a[i] = b[i - na + nb];
    }

    cout << endl << "    Mảng a sau khi nối: ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

bool kiemTra_op49(int b[], int bi, int i)
{
    for (int j = 0; j < i; j++)
    {
        if (b[j] == bi) return true;
    }

    return false;
}

int op49()
{
    int b[MAX], nb;

    do
    {
        cout << endl << "49. Nhập số phần tử mảng b để kiểm tra: "; cin >> nb;
    } while (nb <= 0);

    for (int i = 0; i < nb; i++)
    {
        cout << "    b[" << i << "] = "; cin >> b[i];

        while (kiemTra_op49(b, b[i], i))
        {
            cout << "    Hãy nhập lại: " << endl;
            cout << "    b[" << i << "] = "; cin >> b[i];
        }
    }

    cout << "    Mảng vừa nhập: ";
    
    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}

int op50()
{
    int k, m, bk, b[MAX];

    for (int i = 0; i < na; i++)
    {
        b[i] = a[i];
    }

    for (int i = 0; i < na; i++)
    {
        for (int j = i + 1; j < na; j++)
        {
            if (b[i] < b[j])
                swap(b[i], b[j]);
        }
    }
    
    do
    {
        cout << endl << "50. Nhập k: "; cin >> k;
    } while (k <= 0);

    m = k;

    for (int i = 0; m > 0; i++)
    {
        if (b[i] > b[i + 1])
        {
            bk = b[i];
            m--;
        }
    }

    cout << "    Phần tử lớn thứ " << k << " của mảng a: " << bk;
    return 0;
}

int op51()
{
    for (int i = 0; i < na / 2; i++)
    {
        swap(a[i], a[na - 1 - i]);
    }

    cout << endl << "51. Mảng a sau khi nghịch đảo: ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

int op52()
{
    int m = 0;

    for (int i = 0; i < na; i++)
    {
        if (a[i] >= a[i + 1]) m++;
    }

    cout << endl << "52. Số mảng con tăng: " << m + 1 << endl;
    return 0;
}

int main()
{
    cout << setw(16) << " " << "CÁC THAO TÁC XỬ LÝ\n";
    cout << setfill('-');
    cout << setw(50) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "45. Tách các số nguyên tố từ mảng a sang mảng b\n";
    cout << "46. Tách mảng a thành 2 mảng b (chứa các số\n    nguyên dương) và c (chứa các số còn lại)\n";
    cout << "47. Tách 1 mảng thành 2 mảng chẵn và lẻ\n";
    cout << "48. Nối 2 mảng số nguyên\n";
    cout << "49. Kiểm tra phần tử mảng 1 chiều khi nhập từ phím\n";
    cout << "50. Chỉ ra số hạng lớn thứ k của mảng\n";
    cout << "51. Đảo ngược dãy số\n";
    cout << "52. Đếm số lượng mảng con tăng có trong mảng\n";
    cout << setw(50) << "-" << endl;

    nhapMang();
    op45();
    op46();
    op47();
    op48();
    op49();
    op50();
    op51();
    op52();

    return 0;
}