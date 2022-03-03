#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int randInt(int min, int max);
void ghiFile(int *p, int n);
void docFile(int n);
void timMax(int *p, int n);

int main() {
    int n;

    do {
        cout << "Nhap so phan tu: ";
        cin >> n;
    } while (n <= 0);

    int *p = new int[n];

    ghiFile(p, n);
    docFile(n);

    delete[] p;
}

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

void ghiFile(int *p, int n) {
    //srand((int)time(0));
    ofstream TEXT("Integer.txt");

    TEXT << "Begin Day" << endl;
    for (int i = 0; i < n; i++) {
        cout << "p[" << i << "] = ";
        cin >> p[i];
        //p[i] = randInt(-9, 9);
        TEXT << p[i] << ' ';
        if ((i + 1) % 20 == 0) TEXT << endl;
    }
    if (n % 20 != 0) TEXT << endl;
    TEXT << "End Day" << endl;
    TEXT.close();
}

void docFile(int n) {
    int *q = new int[n];
    string a, b;
    ifstream TEXT("Integer.txt");

    while (!TEXT.eof()) {
        getline(TEXT, a);
        for (int i = 0; i < n; i++)
            TEXT >> q[i];
        getline(TEXT, b);
    }
    TEXT.close();

    timMax(q, n);
    delete[] q;
}

void timMax(int *q, int n) {
    int M = q[0];

    for (int i = 1; i < n; i++)
        M = max(M, q[i]);
    cout << "Phan tu lon nhat day: " << M << endl;
}