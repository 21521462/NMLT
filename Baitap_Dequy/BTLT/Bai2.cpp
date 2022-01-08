#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define max 8

int A[max][max] = {0};
int X[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int buoc = 0, kt;

int op1(string str, int n)
{
    if (str[n] != '\0')
        return op1(str, n + 1);
    else
        return n;
}

int op2(int i, int k)
{
    if (k == 0 || i == k)
        return 1;
    else
        return op2(i - 1, k - 1) + op2(i - 1, k);
}

bool xetViTri(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        //trùng cột hoặc cùng nằm trên đường chéo sẽ trả về false
        if (A[0][i] == y || abs(A[0][i] - y) == abs(i - x))
            return false;
    }
    
    //thử hết các cột đều ổn thì trả về true
    return true;
}

void xuatMang1D()
{
    for (int i = 0; i < 7; i++)
    {
        cout << A[0][i] << " ";
    }

    cout << endl;
}

void op3(int i)
{
    for (int j = 0; j < 7; j++) //thử từng cột rồi gán vị trí
    {
        if (xetViTri(i, j))
        {
            A[0][i] = j;

            if (i == 7) xuatMang1D(); //thử hết 8 hàng thì in ra
            op3(i + 1); 
        }
    }
}

void xuatMang2D(int kt)
{
    for (int i = 0; i < kt; i++)
    {
        for (int j = 0; j < kt; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
}

void op4(int x, int y)
{
    ++buoc;
    A[x][y] = buoc;

    for (int i = 0; i < 8; i++) // 8 vị trí có thể đi
    {
        if (buoc == kt * kt) //kiểm tra xem đã đi hết bàn cờ chưa
        {
            cout << "Các bước đi là: " << endl;
            xuatMang2D(kt);
            exit(0);
        }

        int a = x + X[i];
        int b = y + Y[i];

        if (0 <= a && a < kt && 0 <= b && b < kt && A[a][b] == 0) //kiểm tra tính hợp lệ của bước đi
            op4(a, b); //đi bước tiếp theo
    }

    //nếu sai hết thì giảm số bước và trả lại vị trí ô trống
    --buoc;
    A[x][y] = 0;
}

int main()
{
    int op, n, a, b;
    string str;

    cout << setw(8) << " " << "BÀI TẬP ĐỆ QUY TRÊN MẢNG" << endl;
    cout << setfill('-');
    cout << setw(40) << "-" << endl;
    cout << "1. Xác định chiều dài chuỗi." << endl;
    cout << "2. Hiển thị n dòng của tam giác Pascal." << endl;
    cout << "3. Bài toán 8 hậu." << endl;
    cout << "4. Bai toán mã đi tuần." << endl;
    cout << setw(40) << "-" << endl;
    
    do
    {
        cout << "Nhập lựa chọn của bạn: "; cin >> op;
    } while (op < 1 && op > 4);

    switch (op)
    {
    case 1:
        cout << "Nhập chuỗi: ";
        cin.ignore(1000, '\n');
        getline(cin, str);
        cout << "Chiều dài chuỗi là " << op1(str, 0) << endl;
        break;
    case 2:
        cout << "Nhập n: "; cin >> n;

        for (int i = 0; i <= n; i++)
        {
            for (int k = 0; k <= i; k++)
            {
                cout << op2(i, k) << " ";
            }

            cout << endl;
        }
        break;
    case 3:
        op3(0);
        break;
    case 4:
        cout << "Nhập kích thước bàn cờ: "; cin >> kt;
        cout << "Nhập vị trí ban đầu: "; cin >> a >> b;
        op4(a, b);
        cout << "Không tìm thấy đường đi." << endl;
    default:
        break;
    }
    
    return 0;
}