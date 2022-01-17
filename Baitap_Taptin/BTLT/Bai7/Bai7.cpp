#include <iostream>

using namespace std;

int main() {
    string s;
    int i;
    float f;
    long l;

    //chuyen string sang int
    const char *si = s.c_str();
    cout << "Chuyen string sang int" << endl;
    s = "123"; i = atoi(si);
    cout << s << "=>" << i << endl;
    s = "-123b"; i = atoi(si);
    cout << s << "=>" << i << endl;

    //chuyen string sang float
    const char *sf = s.c_str();
    cout << "Chuyen string sang float" << endl;
    s = "2438.55"; f = atof(sf);
    cout << s << "=>" << f << endl;
    s = "656.44fs"; f = atof(sf);
    cout << s << "=>" << f << endl;

    //chuyen string sang long
    const char *sl = s.c_str();
    cout << "Chuyen string sang long" << endl;
    s = "1111.22sfs"; l = atol(sl);
    cout << s << "=>" << l << endl;
    s = "342436.4623"; l = atol(sl);
    cout << s << "=>" << l << endl;

    return 0;
}