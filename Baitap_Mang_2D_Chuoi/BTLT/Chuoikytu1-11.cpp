#include  <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

void nhapChuoi(char s[]) {
    cout << "Nhập chuỗi: ";
    gets(s);
}

void xuatChuoi(char s[]) {
    cout << "Chuỗi: ";
    puts(s);
}

int Bai1(char s[]) {
    char ch;

    cout << "1. ";
    nhapChuoi(s);
    cout << "   Nhập ký tự cần tìm: "; cin.get(ch);
    fflush(stdin);

    for (int i = 0; i < strlen(s); i++)
        if (s[i] == ch) {
            cout << "   Vị trí đầu tiên mà ký tự xuất hiện trong chuỗi: " << i << "\n\n";
            return 0;
        }

    cout << "   Không tìm thấy.\n\n";
    return 0;
}

int Bai2(char s[]) {
    char c;
    bool b = false;

    cout << "2. ";
    nhapChuoi(s);
    cout << "   Nhập ký tự c cần tìm: "; cin.get(c);
    fflush(stdin);

    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c) b = true;

    if (b == true) {
        cout << "   Các vị trí ký tự '" << c << "' xuất hiện: ";

        for (int i = 0; i < strlen(s); i++)
            if (s[i] == c) cout << i << " ";

        cout << "\n\n";
    }
    else cout << "   Ký tự '" << c << "' không xuất hiện.\n\n";
    
    return 0;
}

int Bai3(char s[]) {
    char s1[MAX];

    cout << "3. ";
    nhapChuoi(s);
    cout << "   Nhập chuỗi con: ";
    gets(s1);

    if (strstr(s, s1)) {
        cout << "   Có tìm thấy ở vị trí: ";

        for (int i = 0; i < strlen(s); i++)
            if (strstr(s, s1) == &s[i]) cout << i << "\n\n";
    }
    else cout << "   Không tìm thấy.\n\n";

    return 0;
}

int Bai4(char s[]) {
    char c, c1;

    cout << "4. ";
    nhapChuoi(s);
    cout << "   Nhập ký tự thay thế: "; cin.get(c1);
    fflush(stdin);
    cout << "   Nhập ký tự bị thay thế: "; cin.get(c);
    fflush(stdin);

    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c) s[i] = c1;
    
    cout << "   Sau khi thay:\n   ";
    xuatChuoi(s);
    cout << "\n";
    return 0;
}

int Bai5(char s[]) {
    char c;
    int m = 0;

    cout << "5. ";
    nhapChuoi(s);
    cout << "   Nhập ký tự c: "; cin.get(c);
    fflush(stdin);

    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c) m++;

    cout << "   Số lần xuất hiện của '" << c << "': " << m << "\n\n";
    return 0;
}

int Bai6(char s[]) {
    char c, c1;

    cout << "6. ";
    nhapChuoi(s);
    cout << "   Nhập ký tự thay thế: "; cin.get(c1);
    fflush(stdin);
    cout << "   Nhập ký tự bị thay thế: "; cin.get(c);
    fflush(stdin);

    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c) s[i] = c1;
    
    cout << "   Sau khi thay:\n   ";
    xuatChuoi(s);
    cout << endl;
    return 0;
}

int Bai7(char s[]) {
    cout << "7. ";
    nhapChuoi(s);
    cout << "   Các ký tự in hoa: ";

    for (int i = 0; i < strlen(s); i++)
        if ('A' <= s[i] && s[i] <= 'Z')
            cout << s[i] << " ";

    cout << "\n\n";
    return 0;
}

int Bai8(char s[]) {
    cout << "8. ";
    nhapChuoi(s);
    cout << "   Sau khi đổi chữ xen kẻ 1 chữ hoa 1 chữ thường:\n   Chuỗi: ";

    for (int i = 0; i < strlen(s); i++) {
        if (i % 2 == 0 && s[i] >= 'a') s[i] = toupper(s[i]);
        if (i % 2 == 1 && s[i] <= 'Z') s[i] = tolower(s[i]);
        cout << s[i];
    }

    cout << "\n\n";
    return 0;
}

int Bai9(char s[]) {
    char c;
    int m = 0;

    cout << "9. ";
    nhapChuoi(s);
    cout << "   Nhập ký tự cần đếm: "; cin.get(c);
    fflush(stdin);

    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c) m++;
    
    cout << "   Số lần xuất hiện của ký tự '" << c << "': " << m << "\n\n";
    return 0; 
}

int Bai10(char s[]) {
    int a[MAX + 27], m = 0;

    cout << "10. ";
    nhapChuoi(s);
    cout << "    Ký tự xuất hiện nhiều nhất: ";

    for (int i = 0; i < strlen(s); i++) {
        a[(int)s[i]] = 0;

        for (int j = 0; j < strlen(s); j++)
            if (s[j] == s[i])
                a[(int)s[i]]++;

        m = max(m, a[(int)s[i]]);
    }

    for (int i = 0; i < 127; i++)
        if (a[i] == m) cout << "'" << (char)i << "' ";

    cout << "\n\n";
    return 0;
}

int Bai11(char s[]) {
    char s1[MAX];

    cout << "11. ";
    nhapChuoi(s);
    cout << "    Nhập từ muốn xoá: ";
    gets(s1);
    
    while (strstr(s, s1)) {
        int k;

        for (int i = 0; i < strlen(s); i++)
            if (strstr(s, s1) == &s[i]) {
                k = i;
                break;
            }

        for (int i = k; i < strlen(s); i++)
            s[i] = s[i + strlen(s1)];

        if (!strstr(s, s1)) {
            cout << "    Sau khi xoá:\n    ";
            xuatChuoi(s);
            return 0;
        }
    }
    
    cout << "    Từ không xuất hiện trong chuỗi.\n\n";
    return 0;
}

int main() {
    char s[MAX];

    cout << setw(24) << " " << "CHUỖI KÝ TỰ\n";
    cout << setfill('-');
    cout << setw(59) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "1. Tìm vị trí ký tự xuất hiện đầu tiên trong chuỗi\n";
    cout << "2. Tìm vị trí xuất hiện của ký tự c trong chuỗi s\n";
    cout << "3. Tìm chuỗi con trong 1 chuỗi\n";
    cout << "4. Thay thế ký tự trong chuỗi\n";
    cout << "5. Đếm số lần xuất hiện của ký tự c trong chuỗi s\n";
    cout << "6. Thay thế ký tự bất kì trong chuỗi bằng ký tự mới\n";
    cout << "7. Xuất các ký tự in hoa trong chuỗi\n";
    cout << "8. Đổi chữ xen kẻ 1 chữ hoa và 1 chữ thường\n";
    cout << "9. Đếm một ký tự xuất hiện bao nhiêu lần trong chuỗi\n";
    cout << "10. Tìm kiếm xem ký tự nào xuất hiện nhiều nhất trong chuỗi\n";
    cout << "11. Nhập vào một từ và xoá từ đó trong chuỗi đã cho\n";
    cout << setw(59) << "-" << endl;

    Bai1(s);
    Bai2(s);
    Bai3(s);
    Bai4(s);
    Bai5(s);
    Bai6(s);
    Bai7(s);
    Bai8(s);
    Bai9(s);
    Bai10(s);
    Bai11(s);

    return 0;
}