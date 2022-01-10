#include <iostream>

using namespace std;

int *capPhat(int &n) {
    cout << "Nhap so so nguyen n: ";
    cin >> n;

    int *p = new int[n];
    return p;
}

int main() {
    int n;
    int *p = capPhat(n);

    return 0;
}