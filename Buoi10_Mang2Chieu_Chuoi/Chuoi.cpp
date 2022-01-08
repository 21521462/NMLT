#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

int nhapChuoi(char s[MAX])
{
    cout << "Nhập chuỗi: ";
    gets(s);

    return 0;
}

int xuatChuoi(char s[MAX])
{
    cout << "Chuỗi: ";
    puts(s);

    return 0;
}

int Bai1(char s[MAX])
{
    cout << "1. ";
    nhapChuoi(s);
    cout << "   ";
    xuatChuoi(s);
    cout << endl;

    return 0;
}

int Bai2(char s[MAX])
{
    int m = 0;

    cout << "2. ";
    xuatChuoi(s);

    for (int i = 0; i < strlen(s); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z') m++;
    }

    if (m == 0) cout << "   Chuỗi không có ký tự in hoa.\n";
    else
    {
        cout << "   Các kí tự in hoa: ";

        for (int i = 0; i < strlen(s); i++)
        {
            if ('A' <= s[i] && s[i] <= 'Z') 
                cout << s[i] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}

int Bai3(char s[MAX])
{
    char s1[MAX];
    strcpy(s1, s);

    cout << "3. ";
    xuatChuoi(s1);
    cout << "   Chuỗi đảo ngược: ";

    for (int i = strlen(s1); i >= 0; i--)
    {
        cout << s1[i];
    }
    
    cout << endl << endl;
    return 0;
}

int Bai4(char s[MAX])
{
    char s1[MAX];
    strcpy(s1, s);

    cout << "4. ";
    xuatChuoi(s1);
    cout << "   Chuỗi xen kẽ: ";

    for (int i = 0; i < strlen(s1); i++)
    {
        if (i % 2 == 0 && 'Z' < s1[i])
            s1[i] = toupper(s1[i]);
        if (i % 2 == 1 && 'A' <= s1[i] && s1[i] <= 'Z')
            s1[i] = tolower(s1[i]);

        cout << s1[i];
    }

    cout << endl << endl;
    return 0;
}

int Bai5(char s[MAX])
{
    char ch;
    int m = 0;

    cout << "5. ";
    xuatChuoi(s);
    cout << "   Nhập kí tự cần đếm: "; cin >> ch;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ch) m++;
    }

    cout << "   Số lần xuất hiện ký tự " << ch << ": " << m << "\n\n";
    return 0;
}

int Bai6(char s[MAX])
{
    char ch;
    int a[MAX + 27] = {0}, max = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        int m = 1;

        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j]) m++;
        }

        if (max <= m)
        {
            max = m;
            a[(int)s[i]] = max;
        }
    }

    cout << "6. Chuỗi: ";
    xuatChuoi(s);
    cout << "   Số lần xuất hiện nhiều nhất: " << max << endl;
    cout << "   Ký tự xuất hiện nhiều nhất: ";

    for (int i = 32; i < 127; i++)
    {
        if (a[i] == max) cout << (char)i << " ";
    }

    cout << "\n\n";
    return 0;
}

int Bai7(char s[MAX])
{
    cout << "7. ";
    xuatChuoi(s);

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != s[strlen(s) - 1 - i])
        {
            cout << "   Chuỗi không đối xứng.\n\n";
            return 0;
        }
    }

    cout << "   Chuỗi đối xứng.\n\n";
    return 0;
}

int Bai8(char s[MAX])
{
    char s1[MAX], s2[MAX];

    strcpy(s1, s);

    cout << "8. ";
    xuatChuoi(s1);
    cout << "   Nhập từ muốn xoá: ";
    fflush(stdin);
    gets(s2);

    if (strstr(s1, s2))
    {
        while (strstr(s1, s2))
        {
            int k;

            for (int i = 0; i < strlen(s1); i++)
                if (&s1[i] == strstr(s1, s2))
                {
                    k = i;
                    break;
                }

            for (int i = k; i < strlen(s1); i++)
                s1[i] = s1[i + strlen(s2)];

            cout << "   ";
        }

        xuatChuoi(s1);
        cout << "\n";
    }
    else cout << "   Từ không xuất hiện trong chuỗi.\n\n";

    return 0;
}

int main()
{
    char s[MAX];

    cout << setw(27) << " " << "CHUỖI\n";
    cout << setfill('-');
    cout << setw(58) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "1. Nhập mảng, xuất mảng\n";
    cout << "2. Xuất các ký tự in hoa trong chuỗi\n";
    cout << "3. Đảo ngược các kí tự trong chuỗi\n";
    cout << "4. Đổi chữ xen kẽ 1 chữ hoa và 1 chữ thường\n";
    cout << "5. Đếm một ký tự xuất hiện bao nhiêu lần trong chuỗi\n";
    cout << "6. Tìm kiếm xem ký tự nào xuất hiện nhiều nhất trong chuỗi\n";
    cout << "7. Kiểm tra xem chuỗi có đối xứng hay không?\n";
    cout << "8. Nhập vào một từ và xoá từ đó trong chuỗi đã cho\n";
    cout << setw(58) << "-" << endl;

    Bai1(s);
    Bai2(s);
    Bai3(s);
    Bai4(s);
    Bai5(s);
    Bai6(s);
    Bai7(s);
    Bai8(s);

    return 0;
}