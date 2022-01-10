#include <iostream>
#include <fstream>

using namespace std;

void ghiFile(int **p, int &n);
void docFile();
void Min_Max(int **p, int n);
void dongMax(int **p, int n);

int main() {
    int **p = new int*[10];
    int n;
    
    cout << "Nhap cap cua ma tran: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        p[i] = new int[n];
    
    ghiFile(p, n);
    docFile();
    Min_Max(p, n);
    dongMax(p, n);

    return 0;
}

void ghiFile(int **p, int &n) {
    ofstream TEXT("matran.txt");

    if (!TEXT) {
        cout << "Khong mo duoc file.\n";
        exit(0);
    }

    TEXT << n << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> p[i][j];
            TEXT << p[i][j] << ' ';
        }
        TEXT << endl;
    }
    TEXT.close();
}

void docFile() {
    ifstream TEXT("matran.txt");
    
    for (string str; getline(TEXT, str);)
        cout << str << endl;

    TEXT.close();
}

void Min_Max(int **p, int n) {
    int m = p[0][0], M = p[0][0];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            m = min(m, p[i][j]);
            M = max(M, p[i][j]);
        }

    cout << "Phan tu lon nhat, nho nhat la: " << M << ", " << m << endl;
}

void dongMax(int **p, int n) {
    int a[n];

    for (int i = 0; i < n; i++) {
        a[i] = 0;

        for (int j = 0; j < n; j++)
            a[i] += p[i][j];
    }
    
    int dM = a[0], idM = 0;

    for (int i = 1; i < n; i++)
        if (dM < a[i]) {
            dM = a[i];
            idM = i;
        }
    
    cout << "Dong " << idM + 1 << " tong so phan tu lon nhat: ";
    for (int j = 0; j < n; j++)
        cout << p[idM][j] << ' ';
    cout << endl;
}