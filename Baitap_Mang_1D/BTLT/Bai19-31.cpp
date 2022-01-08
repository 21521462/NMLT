#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iomanip>

using namespace std;

#define MAX 100

int a[MAX], na, nb, X;
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
        cout << "Nhập số phần tử cho mảng số nguyên: "; cin >> na;
        cout << "Nhập số phần tử cho mảng số thực: "; cin >> nb;
    } while (na <= 0 || nb <= 0);

    cout << "Mảng số nguyên vừa nhập: ";

    for (int i = 0; i < na; i++)
    {
        a[i] = randInt(-5, 5);
        cout << a[i] << " ";
    }
    cout << endl << "Mảng số thực vừa nhập: ";
    
    for (int i = 0; i < nb; i++)
    {
        b[i] = randFloat(-5, 5);
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op19()
{
    for (int i = 1; i < nb ; i++)
    {
        for (int j = i; j < nb; j++)
        {
            b[j] = b[j + 1];
        }
        nb--;
    }

    cout << "19. Mảng số thực sau khi xoá phần tử tại vị trí lẻ: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op20()
{
    float m = b[0], n = 0;
    for (int i = 1; i < nb; i++)
    {
        if (m < b[i])
        {
            m = b[i];
            n = i;
        }
    }

    for (int i = n; i < nb; i++)
    {
        b[i] = b[i + 1];
    }

    nb--;

    cout << "20. Mảng số thực sau khi xoá phần tử lớn nhất: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op21()
{
    cout << setw(4) << " " << "Nhập X: "; cin >> X;

    for (int i = 0; i < nb; i++)
    {
        if (b[i] < X)
        {
            for (int j = i; j < nb; j++)
            {
                b[j] = b[j + 1];
            }

            nb--;
            i--;
        }
    }

    cout << "21. Mảng số thực sau khi xoá các phần tử nhỏ hơn " << X << ": ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op22()
{
    float m = abs(b[0] - X), n = 0;

    for (int i = 0; i < nb; i++)
    {
        if (abs(b[i] - X) < m)
        {
            m = abs(b[i] - X);
            n = i;
        }
    }

    for (int i = n; i < nb; i++)
    {
        b[i] = b[i + 1];
    }

    nb--;

    cout << "22. Mảng số thực sau khi xoá phần tử có giá trị gần " << X << " nhất: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op23()
{
    nb++;

    for (int i = nb - 1; i >= 1; i--)
    {
        b[i] = b[i - 1];
    }

    b[0] = X;

    cout << "23. Mảng số thực sau khi chèn " << X << " vào vị trí đầu: ";

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op24()
{
    float m = b[0], n = 0;
    for (int i = 1; i < nb; i++)
    {
        if (m < b[i])
        {
            m = b[i];
            n = i;
        }
    }

    nb++;

    for (int i = nb - 1; i > n; i--)
    {
        if (i != n + 1)
        {
            b[i] = b[i - 1];
        }
        else b[i] = X;
    }

    cout << "24. Mảng số thực sau khi chèn " << X << " vào phía sau phần tử lớn nhất: "; 

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int op25()
{
    for (int i = 0; i < na; i++)
    {
        if (abs(a[i]) % 2 == 0)
        {
            na++;
            for (int j = na - 1; j > i ; j--)
            {
                if (j == i + 1) a[j] = X;
                else a[j] = a[j - 1];
            }
            i++;
        }
    }

    cout << "25. Mảng số nguyên sau khi chèn " << X << " vào phía sau tất cả phần tử chẵn: "; 

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

bool kiemTraSNT(int ai)
{
    int m = 0;

    for (int i = 1; i <= sqrt(ai); i++)
    {
        if (ai % i == 0) m++;
    }

    if (m == 1 && ai != 1) return true;
    else return false;
}

int op26()
{
    for (int i = 0; i < na; i++)
    {
        if (kiemTraSNT(a[i]))
        {
            na++;
            for (int j = na - 1; j > i; j--)
            {
                if (j == i + 1) a[j] = 0;
                else a[j] = a[j - 1];
            }
        }
    }

    cout << "26. Mảng số nguyên sau khi thêm số 0 đằng sau các số nguyên tố: ";

    for (int i = 0; i< na; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

int op27()
{
    for (int i = 0; i < na; i++)
    {
        if (kiemTraSNT(a[i]))
        {
            for (int j = i; j < na; j++)
            {
                a[j] = a[j + 1];
            }

            na--;
            i--;
        }
    }

    cout << "27. Mảng số nguyên sau khi xoá tất cả số nguyên tố: ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

int op28()
{
    cout << "28. Tạo mảng số nguyên mới: ";

    for (int i = 0; i < na; i++)
    {
        a[i] = randInt(-5, 5);
        cout << a[i] << " ";
    }

    for (int i = 0; i < na; i++)
    {
        if (kiemTraSNT(a[i]))
        {
            a[i] = 0;
        }
    }

    cout << endl << setw(4) << " " << "Mảng số nguyên sau khi sửa các số nguyên tố thành số 0: ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

int op29()
{
    for (int i = 0; i < na; i++)
    {
        if (a[i] < 0)
        {
            for (int j = i; j < na; j++)
            {
                a[j] = a[j + 1];
            }

            na--;
            i--;
        }
    }

    cout << "29. Mảng số nguyên sau khi xoá các phần tử âm: ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

int op30()
{
    for (int i = 0; i < na; i++)
    {
        if (a[i] == X)
        {
            for (int j = i; j < na; j++)
            {
                a[j] = a[j + 1];
            }

            na--;
            i--;
        }
    }

    cout << "30. Mảng số nguyên sau khi xoá các phần tử trùng với " << X << ": ";

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

int op31()
{
    cout << "31. Nhập X mới: "; cin >> X;
    cout << setw(4) << " " << "Mảng số thực sau khi sắp xếp tăng dần: ";

    for (int i = 0; i < nb; i++)
    {
        for (int j = i + 1; j < nb; j++)
        {
            if (b[i] > b[j]) swap(b[i], b[j]);
        }

        cout << b[i] << " ";
    }

    cout << endl << setw(4) << " " << "Mảng số thực sau khi chèn " << X << " để dãy vẫn tăng dần: ";

    for (int i = 0; i < nb; i++)
    {
        if (X >= b[nb - 1])
        {
            nb++;

            b[nb] = b[nb - 1];
            b[nb - 1] = X;
            break;
        }
        if (X <= b[i])
        {
            nb++;

            for (int j = nb - 1; j > i; j--)
            {
                b[j] = b[j - 1];
            }

            b[i] = X;
            break;
        }
    }

    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

int main()
{
    cout << setw(19) << " " << "CÁC THAO TÁC THÊM/XOÁ/SỬA\n";
    cout << setfill('-');
    cout << setw(62) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "19. Xoá phần tử tại vị trí lẻ trong mảng\n";
    cout << "20. Xoá phần tử có giá trị lớn nhất trong mảng\n";
    cout << "21. Xoá tất cả các phần tử nhỏ hơn X\n";
    cout << "22. Xoá phần tử có giá trị gần X nhất\n";
    cout << "23. Chèn X vào vị trí đầu của mảng 1 chiều\n";
    cout << "24. Chèn X vào phía sau phần tử có giá trị lớn nhất trong mảng\n";
    cout << "25. Chèn phần tử X vào tất cả các phần tử chẵn trong mảng\n";
    cout << "26. Thêm số 0 đằng sau các số nguyên tố trong mảng\n";
    cout << "27. Xoá tất cả số nguyên tố trong mảng\n";
    cout << "28. Sửa các số nguyên tố có trong mảng thành số 0\n";
    cout << "29. Viết hàm xoá tất cả các phần tử có giá trị là số âm\n    trong mảng số nguyên a có n phần tử\n";
    cout << "30. Xoá các phần tử trung với X trong mảng 1 chiều\n";
    cout << "31. Chèn X vào dãy sao cho dãy vẫn có thứ tự tăng dần\n";
    cout << setw(62) << "-" << endl;
    cout << setfill(' ');

    nhapMang();
    op19();
    op20();
    op21();
    op22();
    op23();
    op24();
    op25();
    op26();
    op27();
    op28();
    op29();
    op30();
    op31();

    return 0;
}