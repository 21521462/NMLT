#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define MAX 100

int main() {
    fstream file;
    float s1 = 0, s2 = 0, s3 = 0;
    int step = 0, t;

    file.open("trung binh", ios::out);
    if (!file) {
        cout << "Khong mo duoc file." << endl;
        return 1;
    }
    file << 46 << "\t" << 56 << "\t" << 12 << endl;
    file << 12 << "\t" << 34 << "\t" << 56 << endl;
    file << 45 << "\t" << 78 << "\t" << 90 << endl;
    file.close();

    file.open("trung binh", ios::in);
    char s_copy[MAX];
    for (string str; getline(file, str);) {
        const char *s = str.c_str();
        strcpy(s_copy, s);
        char *p = strtok(s_copy, "\t");
        step = 0;

        s1 += atoi(p);
        step++;

        while (p != NULL) {
            p = strtok(NULL, "\t");
            if (p != NULL) {
                if (step == 1) s2 += atoi(p);
                else s3 += atoi(p);
                step++;
            }
        }
    }
    s1 /= step; s2 /= step; s3 /= step;
    file.close();

    float f = 100;
    s1 = (int)(s1 * 100) / f;
    s2 = (int)(s2 * 100) / f;
    s3 = (int)(s3 * 100) / f;

    file.open("trung binh", ios::out | ios::app);
    file << s1 << "\t" << s2 << "\t" << s3 << endl;
    file.close();

    return 0;
}