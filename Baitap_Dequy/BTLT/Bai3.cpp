#include <iostream>
#include <string>

using namespace std;

int doDai(string str, int n)
{
    if (str[n] != '\0')
    {
        return doDai(str, n + 1);
    }

    else
    {
        return n;
    }
}

int main()
{
    string str = "abcdefghijklmnopqrstuvwxyz";

    cout << "Độ dài chuỗi là: " << doDai(str, 0) << endl;

    return 0;
}