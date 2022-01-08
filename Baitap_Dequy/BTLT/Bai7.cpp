#include <iostream>
#define MAX 8

using namespace std;

int A[MAX][MAX] = { 0 };
int X[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n;
int buoc = 0;

void Xuat(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
}

void diChuyen(int x, int y)
{
    ++buoc;
    A[x][y] = buoc;

    for (int i = 0; i < 8; i++)
    {
        if (buoc == n * n)
        {
            cout << "Các bước đi là:" << endl;
            Xuat(n);
            exit(0);
        }

        int a = x + X[i];
        int b = y + Y[i];

        if (0 <= a && a < n && 0 <= b && b < n && A[a][b] == 0)
        {
            diChuyen(a, b);
        }
    }

    --buoc;
    A[x][y] = 0;
}

int main()
{
    cout << "Nhập kích thước bàn cờ: "; cin >> n;

    int a, b;

    cout << "Nhập vị trí ban đầu:" << endl;
    cout << "x: "; cin >> a;
    cout << "y: "; cin >> b;

    diChuyen(a, b);

    cout << "Không tìm thấy đường đi." << endl;
}