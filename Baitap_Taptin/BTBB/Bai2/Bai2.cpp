#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 100

int randInt(int min, int max);
void ghiFile(int **p, int n);
void docFile();
void timMinMax(int **q, int n);
void timDongMax(int **q, int n);

int main() {
    int n;

    do {
        cout << "Nhap cap cua ma tran: ";
        cin >> n;
    } while (n <= 0);

    int **p = new int*[n];

    for (int i = 0; i < n; i++)
        p[i] = new int[n];

    ghiFile(p, n);
    docFile();

    for (int i = 0; i < n; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

void ghiFile(int **p, int n) {
    srand((int)time(0));
    ofstream TEXT("matran.txt");

    TEXT << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = randInt(0, 9);
            TEXT << p[i][j] << ' ';
        }
        TEXT << endl;
    }
    TEXT.close();
}

void docFile() {
    int n, **q = new int*[MAX];
    ifstream TEXT("matran.txt");

    for (int i = 0; i < MAX; i++)
        q[i] = new int[MAX];

    while (!TEXT.eof()) {
        TEXT >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                TEXT >> q[i][j];
    }

    timMinMax(q, n);
    timDongMax(q, n);
}

void timMinMax(int **q, int n) {
    int M = q[0][0], m = q[0][0];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            M = max(M, q[i][j]);
            m = min(m, q[i][j]);
        }
    cout << "Phan tu lon nhat, nho nhat: " << M << ", " << m << endl;
}

void timDongMax(int **q, int n) {
    int d = 0, Sd = 0;

    for (int i = 0; i < n; i++) {
        int S = 0;

        for (int j = 0; j < n; j++)
            S += q[i][j];
        
        if (Sd < S) {
            Sd = S;
            d = i;
        }
    }

    cout << "Dong " << d + 1 << " co tong so cac phan tu lon nhat: ";

    for (int j = 0; j < n; j++)
        cout << q[d][j] << ' ';
    cout << endl;
}