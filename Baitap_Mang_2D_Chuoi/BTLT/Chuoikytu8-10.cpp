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

int Bai8(char s[MAX]) {
    cout << "8. ";
    nhapChuoi(s);

    for (int i = 0; i < strlen(s) / 2; i++)
        if (s[i] != s[strlen(s) - 1 - i]) {
            cout << "   Mảng không đối xứng.\n\n";
            return 0;
        }

    cout << "   Mảng đối xứng.\n\n";
    return 1;
}

int Bai9(char s[MAX]) {
    cout << "9. ";
    nhapChuoi(s);

    int i = 0;

    while (s[i] != '\0') i++;

    cout << "   Độ dài chuỗi: " << i << "\n\n";
    return 0;
}

int Bai10(char s[MAX]) {
    cout << "10. ";
    nhapChuoi(s);
    cout << "    Sau khi đảo ngược:\n    ";

    for (int i = 0; i < strlen(s) / 2; i++) {
        swap(s[i], s[strlen(s) - 1 - i]);
    }

    xuatChuoi(s);
    cout << endl;
    return 0;
}

int main() {
    char s[MAX];

    cout << setw(16) << " " << "CHUỖI KÝ TỰ\n";
    cout << setfill('-');
    cout << setw(43) << "-" << endl;
    cout << "8. Viết hàm kiểm tra đối xứng, nếu đối xứng\n    trả về 1, nếu không trả về 0\n";
    cout << "9. Tính độ dài chuỗi\n";
    cout << "10. Đảo ngược các ký tự trong chuỗi\n";
    cout << setw(43) << "-" << endl;

    Bai8(s);
    Bai9(s);
    Bai10(s);

    return 0;
}