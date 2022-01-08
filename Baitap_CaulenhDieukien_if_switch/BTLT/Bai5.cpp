#include <iostream>

using namespace std;

void layChuSo(int n)
{
    cout << "Chữ số hàng trăm: " << n / 100 << endl;
    cout << "Chữ số hàng chục: " << (n / 10) % 10 << endl;
    cout << "Chữ số hàng đơn vị: " << n % 10 << endl;
}

int main()
{
    int n;

    do
    {
        cout << "Nhập n có 3 chữ số: "; cin >> n;
    } while (n < 100 || n > 999);
    
    layChuSo(n);

    return 0;
}