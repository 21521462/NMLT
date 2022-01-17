#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 100

struct SV {
    char ma[10];
    char ten[MAX];
    char ns[4];
    float dtb;
} sv[MAX];

void ghiFile(int N, int n);
void docFile();
void timMa();
    
int main() {
    int n = 0, N;

    cout << "Nhap so luong sinh vien: ";
    cin >> N;

    ifstream file("students.txt");
    for (string str; getline(file, str);) n++;
    n = n / 5 + 1;
    N += n;
    file.close();

    ghiFile(N, n);
    docFile();
    timMa();

    return 0;
}

void ghiFile(int N, int n) {
    ofstream file("students.txt", ios::app);
    for (int i = 0; i < N - n; i++) {
        file << n + i << '.' << endl;
        cin.ignore();
        cout << "Nhap ma sinh vien thu " << n + i << ": "; cin.getline(sv[i].ma, 11);
        file << "Ma so sinh vien: " << sv[i].ma << endl;
        cout << "Nhap ho ten: "; cin.getline(sv[i].ten, 101);
        file << "Ho va ten: " << sv[i].ten << endl;
        cout << "Nhap nam sinh: "; cin.getline(sv[i].ns, 5);
        file << "Nam sinh: " << sv[i].ns << endl;
        cout << "Nhap diem trung binh: "; cin >> sv[i].dtb;
        file << "Diem trung binh: " << sv[i].dtb << endl;
    }
    file.close();
}

void docFile() {
    ifstream file("students.txt");
    for (string str; getline(file, str);)
        cout << str << endl;
    file.close();
}

void timMa() {
    char s1[10];
    cout << "Nhap ma can tim: ";
    cin.ignore();
    cin.getline(s1, 10);

    ifstream file("students.txt");
    for (string str1; getline(file, str1);) {
        const char *s2 = str1.c_str();
        if (strstr(s2, s1)) {
            int n = 3;
            cout << "Ket qua:\n" << str1 << endl;
            while (n > 0) {
                string str2;
                getline(file, str2);
                cout << str2 << endl;
                n--;
            }
            return;
        }
    }
    file.close();
}