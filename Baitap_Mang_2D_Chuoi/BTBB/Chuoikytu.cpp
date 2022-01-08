#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

void nhapChuoi(char s[MAX]) {

    cout << "Nhập chuỗi: ";
    gets(s);
}

void xuatChuoi(char s[MAX]) {
    
    cout << "Chuỗi: ";
    puts(s);
}

int Bai4(char s[MAX]) {

    int m = 0;

    cout << "4. ";
    nhapChuoi(s);
    cout << "   ";
    xuatChuoi(s);

    for (int i = 0; i < strlen(s); i++)
        if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0')) m++;
    
    cout << "   Số từ trong chuỗi: " << m << "\n\n";
    return 0;
}

int Bai5(char s[MAX]) {

    cout << "5. ";
    xuatChuoi(s);

    for (int i = 0; i < strlen(s); i++) {
        if (i == 0) s[i] = toupper(s[i]);
        else
            if (s[i] == ' ') s[i + 1] = toupper(s[i + 1]);
    }

    cout << "   Sau khi đổi ký tự đầu tiên của mỗi từ thành chữ in hoa:\n   ";
    xuatChuoi(s);
    return 0;
}

int Bai6(char s[MAX]) {

    cout << "6. ";
    xuatChuoi(s);

    while (s[0] == ' ')
        for (int i = 0; i < strlen(s); i++)
            s[i] = s[i + 1];

    while (s[strlen(s)] == ' ')
        s[strlen(s)] = '\0';

    for (int i = 0; i < strlen(s); i++) {
        while (s[i] == ' ' && s[i + 1] == ' ')
            for (int j = i; j < strlen(s); j++)
                s[j] = s[j + 1];
    }

    cout << "   Sau khi bỏ các ký tự khoảng trắng thừa:\n   ";
    xuatChuoi(s);
    return 0;
}

int main() {

    char s[MAX];

    cout << setw(19) << " " << "CHUỖI KÝ TỰ\n";
    cout << setfill('-');
    cout << setw(49) << "-" << endl;
    cout << "Chương trình sẽ thực hiện các chức năng sau:\n";
    cout << "4. Đếm số từ trong một chuỗi\n";
    cout << "5. Đối kí tự đầu tien của mỗi từ thành chữ in hoa\n";
    cout << "6. Bỏ các ký tự khoảng trắng thừa\n";
    cout << setw(49) << "-" << endl;

    Bai4(s);
    Bai5(s);
    Bai6(s);

    return 0;
}