#include <iostream>

using namespace std;

int main()
{
    char ch[20];
    int a[20], l, k;

    cout << "Nhập số la mã: ";
    gets(ch);

    l = strlen(ch);

    for (int i = 0; i < l; i++)
    {
        switch (ch[i])
        {
        case 'I':
            a[i] = 1;
            break;
        case 'V':
            a[i] = 5;
            break;
        case 'X':
            a[i] = 10;
            break;
        case 'L':
            a[i] = 50;
            break;
        case 'C':
            a[i] = 100;
            break;
        case 'D':
            a[i] = 500;
            break;
        case 'M':
            a[i] = 1000;
            break;
        default:
            cout << "Hãy nhập lại số la mã." << endl;
            return 0;
        }
    }
    
    k = a[l - 1];

    for (int i = l - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            k = k - a[i - 1];
        }
        
        else
        {
            k = k + a[i - 1];
        }
    }

    cout << "Giá trị thập phân tương ứng là: " << k << endl;

    return 0;
}