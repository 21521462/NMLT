#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int S = 0, temp, n;
    fstream file;

    file.open("ARRAY.INP", ios::in);
    if (!file) {
        cout << "Khong mo duoc file." << endl;
        return 1;
    }
    file >> n;
    for (int i = 0; i < n; i++) {
        file >> temp;
        S += temp;
    }
    file.close();

    file.open("ARRAY.INP", ios::out | ios::app);
    file << "Tong cac phan tu: " << S << endl;
    file.close();
    
    return 0;
}