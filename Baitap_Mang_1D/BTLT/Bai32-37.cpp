#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define MAX 100

int a[MAX], b[MAX], na, nb;

int nhapMang(int a[], int &n, char ch)
{
    do
    {
        cout << "Nhập số phần tử mảng " << ch << ": "; cin >> n;
    } while(n <= 0);

    for (int i = 0; i < n; i++)
    {
        cout << "    " << (char)(ch + 32) << "[" << i << "] = "; cin >> a[i];
    }

    cout << "    Mảng vừa nhập: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

int op32()
{
    cout << "32. ";
    nhapMang(a, na, 'A');

    int m = 0, n = 0;

    for (int i = 0; i < na; i++)
    {
        if (a[i] % 2 == 0) m++;
        else n++;
    }

    if (m == na) cout << "    Mảng đã cho là mảng toàn chẵn.\n";
    else if (n == na) cout << "    Mảng đã cho là mảng toàn lẻ.\n";
    else cout << "    Mảng đã cho không toàn chẵn cũng không toàn lẻ.\n";

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

int op33()
{
    cout << "33. ";
    nhapMang(a, na, 'A');

    int m = 0;

    for (int i = 0; i < na; i++)
    {
        if (kiemTraSNT(a[i])) m++;
    }

    if (m == na) cout << "    Mảng đã cho là mảng toàn số nguyên tố.\n";
    else cout << "    Mảng đã cho không là mảng toàn số nguyên tố.\n";

    return 0;
}

int op34()
{
    cout << "34. ";
    nhapMang(a, na, 'A');

    int m = 0, n = 0;

    for (int i = 0; i < na - 1; i++)
    {
        if (a[i] < a[i + 1]) m++;
        if (a[i] > a[i + 1]) n++;
    }

    if (m == na - 1) cout << "    Mảng đã cho là mảng tăng dần.\n";
    else if (n == na - 1) cout << "    Mảng đã cho là mảng giảm dần.\n";
    else cout << "    Mảng đã cho không tăng cũng không giảm.\n";

    return 0;
}

int op35()
{
    cout << "35. ";
    nhapMang(a, na, 'A');

    int m = 0;

    for (int i = 0; i < na / 2; i++)
    {
        if (a[i] == a[na - 1 - i]) m++;
    }

    if (m == na / 2) cout << "    Mảng đã cho là mảng đối xứng.\n";
    else cout << "    Mảng đã cho là mảng không đối xứng.\n";

    return 0;
}

int op36()
{
    cout << "36. ";
    nhapMang(a, na, 'A');
    cout << "    ";
    nhapMang(b, nb, 'B');
    
    if (nb < na)
    {   
        do
        {
            cout << "    Nhập số phần tử dãy B >= số phần tử dãy A.\n";
            nhapMang(b, nb, 'B');
        } while (nb < na);
    }

    int m = a[0];

    for (int i = 0; i < nb; i++)
    {
        if (b[i] == m)
        {
            int dem = 1, n = 1;

            for (int j = i + 1; n < na; j++, n++)
            {
                if (b[j] == a[n]) dem++;
            }

            if (dem == na)
            {
                cout << "Mảng A là mảng con của mảng B.\n";
                break;
            }
        }

        if (i == nb - 1) cout << "Mảng A không là mảng con của mảng B.\n";
    }

    return 0;
}

int op37()
{
    int m = 0;

    cout << "37. ";
    nhapMang(a, na, 'A');

    for (int i = 0; i < na - 1; i++)
    {
        if (a[i] > a[i + 1]) m++;
    }

    if (m == 0) cout << "    Mảng đã cho có thứ tự tăng.\n";
    else cout << "    Mảng đã cho không có thứ tự tăng.\n";

    return 0;
}

int main()
{
    cout << setw(14) << " " << "CÁC THAO TÁC KIỂM TRA\n";
    cout << setfill('-');
    cout << setw(48) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "32. Mảng có phải là mảng toàn chẵn/toàn lẻ?\n";
    cout << "33. Mảng có phải là mảng toàn số nguyên tố?\n";
    cout << "34. Mảng có phải là mảng tăng dần/giảm dần?\n";
    cout << "35. Mảng có đối xứng hay không?\n";
    cout << "36. Mảng A có phải là mảng con của mảng B không?\n";
    cout << "37. Mảng có thứ tự tăng hay không?\n";
    cout << setw(48) << "-" << endl;

    op32();
    op33();
    op34();
    op35();
    op36();
    op37();

    return 0;
}