#include <iostream>

using namespace std;

char kyTuHoa (char t)
{
    char h = char(t - 32);

    return h;
}

int main()
{
    char h;

    cout << "Nhap ky tu thuong: "; cin >> h;
    cout << "Ky tu in hoa la " << kyTuHoa(h) << endl;

    return 0;
}