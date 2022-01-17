#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int randInt(int min, int max);

int main() {
    int a[MAX], n;
    fstream file, file1, file2;

    cout << "Nhap so phan tu: ";
    cin >> n;

    srand((int)time(0));
    for (int i = 0; i < n; i++)
        a[i] = randInt(-20, 20);

    file.open("SONGUYEN.INP", ios::out);
    if (!file) {
        cout << "Khong mo duoc file." << endl;
        return 1;
    }
    for (int i = 0; i < n; i++)
        file << a[i] << ' ';
    file.close();

    int temp;
    file.open("SONGUYEN.INP", ios::in);
    if (!file) {
        cout << "Khong mo duoc file." << endl;
        return 1;
    }
    file1.open("SOCHAN.OUT", ios::out);
    if (!file1) {
        cout << "Khong mo duoc file." << endl;
        return 1;
    }
    file2.open("SOLE.OUT", ios::out);
    if (!file2) {
        cout << "Khong mo duoc file." << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        file >> temp;
        if (temp % 2 == 0) file1 << temp << ' ';
        else file2 << temp << ' ';
    }
    file.close();
    file1.close();
    file2.close();

    return 0;
}

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

