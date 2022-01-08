#include <iostream>

using namespace std;

#define MAX 100

void Nhap(char **&p, int &n) {
    for (int i = 0; i < MAX; i++) {
        gets(p[i]);
        if(p[i][0] == '\0') {
            n = i;
            return;
        }
    }
}

void Xuat(char **p, int n) {
    for (int i = 0; i < n; i++) {
        puts(p[i]);
    }

    cout << endl;
}

void sapXep(char **&p, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < strlen(p[i]); j++)
            for (int k = j + 1; k < strlen(p[i]); k++)
                if (p[i][j] > p[i][k]) swap(p[i][j], p[i][k]);
}

int main() {
    int n;
    char **p = new char*[MAX];

    for (int i = 0; i < MAX; i++)
        p[i] = new char[MAX];

    cout << "Nhap cac dong van ban:\n\n";
    Nhap(p, n);
    cout << "Truoc khi sap xep:\n\n";
    Xuat(p, n);
    sapXep(p, n);
    cout << "Sau khi sap xep:\n\n";
    Xuat(p, n);

    for (int i = 0; i < n; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}