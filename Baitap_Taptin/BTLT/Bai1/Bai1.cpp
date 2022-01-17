#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int randInt(int min, int max);
void ghiFile(int a[], int n);

int main() {
    int n, a[MAX];
    
    cout << "Nhap so phan tu: ";
    cin >> n;

    ghiFile(a, n);

    return 0;
}

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}

void ghiFile(int a[],int n) {
    srand((int)time(0));
    ofstream file("Integer.txt");
    if (!file) {
        cout << "Khong mo duoc file." << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        a[i] = randInt(-10, 10);
        file << a[i] << ' ';
    }
    file << endl;
    file.close();
}