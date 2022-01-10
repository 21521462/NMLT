#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 100

int randInt(int min, int max);
void docFile(int a[], int n);
void ghiFile(int a[], int &n);
void Max(int a[], int n);

int main() {
    int n, a[MAX];

    ghiFile(a, n);
    docFile(a, n);

    return 0;
}

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

void Max(int a[], int n) {
    int M = a[0];

    for (int i = 1; i < n; i++)
        M = max(M, a[i]);
    
    cout << "Phan tu lon nhat: " << M << endl;
}

void ghiFile(int a[], int &n) {
    srand((int)time(0));
    ofstream TEXT("Integer.txt");
    int m = 0;

    if (!TEXT) {
        cout << "Khong mo duoc file.\n";
        exit(0);
    }

    cout << "Nhap so phan tu cua day: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        
    }

    TEXT << "Begin day" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
        
        TEXT << a[i] << ' ';
        m++;

        if (m % 20 == 0) TEXT << endl;
    }
    if (m % 20 == 0) TEXT << "End day" << endl;
    else TEXT << endl << "End day" << endl;

    TEXT.close();
}

void docFile(int a[], int n) {
    char ch;
    ifstream TEXT("Integer.txt");

    while (!TEXT.eof()) {
        TEXT.get(ch);
        if (!TEXT.eof())
            cout << ch;
    }
    TEXT.close();

    Max(a, n);
}