#include <iostream>

using namespace std;

int main() {
    char **p = new char*[12];

    for (int i = 0; i < 12; i++)
        p[i] = new char[12];

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            p[i][j] = 'x';
            cout << p[i][j] << "   ";
        }

        cout << "\n\n";
    }

    for (int i = 0; i < 12; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}