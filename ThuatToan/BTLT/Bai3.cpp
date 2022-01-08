#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter a, b, c: "; cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0)
    {
        if (a < b + c && b < a + c && c < a + b)
        {
            cout << "a, b, c are three sides of a triangle." << endl;
        }
        else
        {
            cout << "a, b, c are not three sides of a triangle." << endl;
        }
    }
    else
    {
        cout << "a, b, c are not three sides of a triangle." << endl;
    }

    return 0;
}