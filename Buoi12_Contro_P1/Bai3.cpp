#include <iostream>

using namespace std;

int main() {
    char str[] = "hello class";
    char *p = str;

    for (int i = 0; i < strlen(str); i++) {
        *(p + i) = toupper(*(p + i));
        cout << *(p + i);
    }

    cout << endl;
    return 0;
}