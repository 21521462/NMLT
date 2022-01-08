#include <iostream>

using namespace std;

int main() {
    int a[10];
    int *p = a;

    *(p + 4) = 100;

    for (int i = 0; i < 10; i++) {
        cout << "a[" << i << "] = ";
        cin >> *(p + i);
    }

    for (int i = 0; i < 10; i++) {
        cout << *(p + i) << " ";
    }

    cout << endl;
    return 0;
}