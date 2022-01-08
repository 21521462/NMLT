#include <iostream>
#include <iomanip>

using namespace std;

#define max 100

void nhapMangThuc(float b[], int &n)
{
    cout << "Nhập số phần tử: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> b[i];
    }
}

void nhapMangNguyen(int a[], int &n)
{
    cout << "Nhập số phần tử: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}

void op1(int a[], int &n)
{
    do
    {
        cout << "Nhập số phần tử (5 < n < 100): "; cin >> n;
    } while (5 >= n || n >= 100);

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}

int op2(int a[], int n, float &x)
{
    cout << "Nhập giá trị muốn tìm kiếm: "; cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Vị trí phần tử đầu tiên có giá trị bằng " << x << " là ";
            return i;
        }
    }

    return -1;
}

int kiemTra_op3(float b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (b[i] < 0) return i;
    }

    return -1;
}

void op3(float b[], int n)
{
    cout << "Các phần tử âm của mảng là: ";

    for (int i = 0; i < n; i++)
    {
        if (b[i] < 0)
            cout << b[i] << " ";
    }

    cout << endl;
}

int kiemTra_op4(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) % 2 == 1)
            return i;
    }

    return -1;
}

void op4(int a[], int n)
{
    cout << "Các phần tử lẻ của mảng: ";

    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) % 2 == 1)
            cout << a[i] << " ";
    }

    cout << endl;
}

int kiemTra_op5(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) % 2 == 0)
            return i;
    }

    return -1;
}

void op5(int a[], int n)
{
    cout << "Các phần tử chẵn và nhỏ hơn 20: ";

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 20 && abs(a[i]) % 2 == 0)
            cout << a[i] << " ";
    }

    cout << endl;
}

int main()
{
    float b[max], x;
    int a[max], n, op, t;

    cout << setw(14) << " " << "CÁC THAO TÁC NHẬP XUẤT" << endl;
    cout << setfill('-');
    cout << setw(50) << "-" << endl;
    cout << "1. Nhập mảng số nguyên có n phần tử (5 < n < 100)." << endl;
    cout << "2. Tìm kiếm giá trị x trong mảng số nguyên." << endl;
    cout << "3. In ra phần tử âm của mảng." << endl;
    cout << "4. In ra các phần tử có giá trị lẻ của mảng." << endl;
    cout << "5. In ra các phần tử chẵn và nhỏ hơn 20." << endl;
    cout << setw(50) << "-" << endl;
    cout << setfill(' ');
    cout << "Nhập lựa chọn của bạn: "; cin >> op;

    switch (op)
    {
    case 1:
        op1(a, n);
        break;
    case 2:
        nhapMangNguyen(a, n);
        cout << op2(a, n, x) << endl;
        break;
    case 3:
        nhapMangThuc(b, n);
        
        if (kiemTra_op3(b, n) == -1)
            cout << "Mảng không có phần tử âm." << endl;
        else
            op3(b, n);
        break;
    case 4:
        nhapMangNguyen(a, n);

        if (kiemTra_op4(a, n) == -1)
            cout << "Mảng không có phần tử lẻ." << endl;
        else
            op4(a, n);
        break;
    case 5:
        nhapMangNguyen(a, n);

        if (kiemTra_op5(a, n) == -1)
            cout << "Mảng không có phần tử chẵn và nhỏ hơn 20." << endl;
        else
            op5(a, n);
        break;
    default:
        cout << "Hãy chọn lại." << endl;
        break;
    }

    do
    {
        cout << "Nhập 1 để lựa chọn hạng mục khác, nhập 0 để kết thúc chương trình." << endl;
        cin >> t;
    } while (t != 1 && t != 0);

    if (t == 1)
        main();
    else
        return 0;
}