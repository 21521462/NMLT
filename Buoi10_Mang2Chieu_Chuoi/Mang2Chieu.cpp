#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

int randInt(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

int nhapMang(int &m, int &n)
{
    do
    {
        cout << "Nhập số dòng (dòng > 0): "; cin >> m;
        cout << "   Nhập số cột (cột > 0): "; cin >> n;
    } while (m <= 0 || n <= 0);

    return 0;
}

int xuatMang(int a[][MAX], int ra, int ca)
{
    srand((int)time(0));

    cout << "   Mảng: " << endl;

    for (int i = 0; i < ra; i++)
    {
        cout << "   ";

        for (int j = 0; j < ca; j++)
        {
            a[i][j] = randInt(0, 9);
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
    
    cout << endl;

    return 0;
}

int Bai1(int a[][MAX], int &ra, int &ca)
{
    cout << "1. ";
    nhapMang(ra, ca);

    /*for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
        }
    }*/ 

    xuatMang(a, ra, ca);

    return 0;
}

int Bai2(int a[][MAX], int ra, int ca)
{
    int x, m = 0;

    cout << "2. Nhập phần tử cần tìm: "; cin >> x;

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            if (a[i][j] == x)
            {
                m++;
                cout << "   Vị trí phần tử: ";
                cout << "(" << i << "," << j << ")\n";
            }
        }
    }

    if (m == 0) cout << "   Không tìm thấy.\n";
    cout << endl;
    return 0;
}

int S(int n)
{
    if (n == 1) return n;
    return n + S(n - 1);
}

int Bai3()
{
    int m = 0, b[MAX][MAX], rb, cb;

    cout << "3. Nhập 1 mảng khác để kiểm tra tính đối xứng.\n   ";

    nhapMang(rb, cb);

    if (rb == cb)
    {
        if (rb == 1)
        {
            cout << "   Mảng đối xứng qua đường chéo chính.\n\n";
            return 0;
        }

        for (int i = 0; i < rb; i++)
        {
            for (int j = 0; j < cb; j++)
            {
                cout << "   b[" << i << "][" << j << "] = ";
                cin >> b[i][j];
            }
        }

        cout << "   Mảng vừa nhập:\n";

        for (int i = 0; i < rb; i++)
        {
            cout << "   ";

            for (int j = 0; j < cb; j++)
            {
                cout << b[i][j] << " ";
            }

            cout << endl;
        }

        for (int i = 0; i < rb; i++)
        {
            for (int p = i + 1; p < rb; p++)
            {
                if (b[i][p] == b[p][i]) m++;
            }
        }

        if (m == S(rb - 1))
            cout << "   Mảng đối xứng qua đường chéo chính.\n\n";
        else
            cout << "   Mảng không đối xứng qua đường chéo chính.\n\n";
    }
    else
        cout << "   Mảng không có đường chéo chính.\n\n";

    return 0;
}

int Bai4(int a[][MAX], int ra, int ca)
{
    int S = 0;

    cout << "4.\n";
    xuatMang(a, ra, ca);
    cout << "   Tổng các phần tử trên dòng:\n";

    for (int i = 0; i < ra; i++)
    {
        int s = 0;

        for (int j = 0; j < ca; j++)
        {
            s += a[i][j];
        }

        S += s;

        cout << "      Dòng " << i << ": " << s << endl;
    }

    cout << "   Tổng các phần tử trên cột:\n";

    for (int j = 0; j < ca; j++)
    {
        int s = 0;

        for (int i = 0; i < ra; i++)
        {
            s += a[i][j];
        }

        cout << "      Cột " << j << ": " << s << endl;
    }

    cout << "   Tổng các phần tử trên toàn mảng: " << S << endl;

    if (ra == ca)
    {
        S = 0;

        for (int i = 0; i < ra; i++)
            S += a[i][i];
    
        cout << "   Tổng các phần tử trên đường chéo chính: " << S << endl;

        int St = 0, Sd = 0;

        for (int i = 0; i < ra; i++)
            for (int j = i + 1; j < ca; j++)
            {
                St += a[i][j];
                Sd += a[j][i];
            }

        cout << "   Tổng các phần tử trên nửa trên: " << St + S << endl;
        cout << "   Tổng các phần tử trên nửa dưới: " << Sd + S << endl << endl;
        return 0;
    }
    else cout << "   Mảng không có đường chéo chính.\n\n";
    return 0;
}

int Bai5(int a[][MAX], int ra, int ca)
{
    cout << "5.\n";
    xuatMang(a, ra, ca);

    int min = a[0][0], max = a[0][0];

    for (int i = 0; i < ra; i++)
        for (int j = 0; j < ca; j++)
        {
            if (min > a[i][j]) min = a[i][j];
            if (max < a[i][j]) max = a[i][j];
        }

    cout << "   Giá trị nhỏ nhất, lớn nhất của mảng: " << min << ", " << max << endl << endl;
    return 0;
}

int Bai6()
{
    int a[MAX][MAX], ra, ca;
    int b[MAX][MAX], rb, cb;

    cout << "6. Nhập mảng thứ nhất:\n   ";

    nhapMang(ra, ca);
    xuatMang(a, ra, ca);

    cout << "   Nhập mảng thứ hai:\n   ";

    nhapMang(rb, cb);
    xuatMang(b, rb, cb);

    if (ra == rb && ca == cb)
    {
        cout << "   Tổng hai ma trận:\n";

        for (int i = 0; i < ra; i++)
        {
            cout << "   ";

            for (int j = 0; j < ca; j++)
            {
                b[i][j] += a[i][j];
                cout << b[i][j] << " ";
            }

            cout << endl;
        }
    }
    else cout << "   Hai mảng không cùng kích thước.\n";

    return 0;
}

int tinhPhanTu(int a[][MAX], int b[][MAX], int r, int c, int m)
{
    int S = 0;

    for (int i = 0; i < m; i++)
    {
        S += a[r][i] * b[i][c];
    }

    return S;
}

int Bai7()
{
    int a[MAX][MAX], ra, ca;
    int b[MAX][MAX], rb, cb;

    cout << "7. Nhập mảng A:\n   ";

    nhapMang(ra, ca);
    xuatMang(a, ra, ca);

    cout << "   Nhập mảng B:\n   ";

    nhapMang(rb, cb);
    xuatMang(b, rb, cb);

    if (ca == rb)
    {
        cout << "   Tích AB:\n";

        for (int i = 0; i < ra; i++)
        {
            cout << "   ";

            for (int j = 0; j < cb; j++)
            {
                cout << tinhPhanTu(a, b, i, j, ca) << " ";
            }

            cout << endl;
        }
    }
    if (cb == ra)
    {
        cout << "   Tích BA:\n";

        for (int i = 0; i < rb; i++)
        {
            cout << "   ";

            for (int j = 0; j < ca; j++)
            {
                cout << tinhPhanTu(b, a, i, j, cb) << " ";
            }

            cout << endl;
        }
    }
    if (ca != rb && cb != ra) cout << "   Không nhân được.\n";

    return 0;
}

int Bai8(int a[][MAX], int ra, int ca)
{
    cout << "8. ";
    nhapMang(ra, ca);

    if (ra != ca)
    {
        cout << "   Đây không phải ma trận đơn vị.\n";
        return 0;
    }

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];

            if (i == j && a[i][j] != 1 || i != j && a[i][j] != 0)
            {
                cout << "   Đây không phải ma trận đơn vị.\n";
                return 0;
            }
        }
    }

    cout << "   Đây là ma trận đơn vị.\n";
    return 0;
}

int main()
{
    int a[MAX][MAX], ra, ca;

    cout << setw(24) << " " << "MẢNG HAI CHIỀU\n";
    cout << setfill('-');
    cout << setw(60) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "1. Nhập mảng, xuất mảng\n";
    cout << "2. Tìm kiếm một phần tử trong mảng\n";
    cout << "3. Kiểm tra mảng có đối xứng qua đường chéo chính hay không?\n";
    cout << "4. Tính tổng các phần tử trên dòng/cột/toàn mảng/đường chéo\n   chính/nửa trên/nửa dưới\n";
    cout << "5. Tìm giá trị nhỏ nhất/lớn nhất của mảng\n";
    cout << "6. Tính tổng hai ma trận\n";
    cout << "7. Tính tích hai ma trận\n";
    cout << "8. Kiểm tra ma trận có phải là ma trận đơn vị không?\n";
    cout << setw(60) << "-" << endl;

    Bai1(a, ra, ca);
    Bai2(a, ra, ca);
    Bai3();
    Bai4(a, ra, ca);
    Bai5(a, ra, ca);
    Bai6();
    Bai7();
    Bai8(a, ra, ca);

    return 0;
}