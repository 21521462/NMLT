#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int randInt(int min, int max);

int main() {
    int s1[MAX], s2[MAX];
    fstream file;

    for (int i = 0; i < MAX;i++)
        s1[i] = randInt(-10, 10);

    //ghi file nhi phan
    file.open("SONGUYEN.INP", ios::out | ios::binary);
    if (!file) {
        cout << "Khong mo duoc file SONGUYEN.INP." << endl;
        return 0;
    }
    file.write(reinterpret_cast<char *>(s1), sizeof(s1));
    file.close();

    //doc file nhi phan
    file.open("SONGUYEN.INP", ios::in | ios::binary);
    if (!file) {
        cout << "Khong mo duoc file SONGUYEN.INP." << endl;
        return 0;
    }
    file.read(reinterpret_cast<char *>(s2), sizeof(s2));
    file.close();

    //sap xep theo thu tu tang dan
    for (int i = 0; i < MAX; i++)
        for (int j = i + 1; j < MAX; j++)
            if (s2[i] > s2[j]) swap(s2[i], s2[j]);

    //ghi file text
    file.open("SONGUYEN.OUT", ios::out);
    if (!file) {
        cout << "Khong mo duoc file SONGUYEN.OUT." << endl;
        return 0;
    }

    for (int i = 0; i < MAX; i++)
        file << s2[i] << ' ';
    file << endl;
    file.close();

    return 0;
}

int randInt(int min, int max) {
    return min + rand() % (max + 1 - min);
}