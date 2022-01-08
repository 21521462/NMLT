#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter a, b, c: "; cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0)
    {
        cout << "This is not a triangle." << endl;
        return 0;
    }

    if (a < b + c && b < a + c && c < a + b)
    {
        if (a == b && a == c)
        {
            cout << "This is a equilateral triangle." << endl;
            return 0;
        }

        else if ((a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) && (a == b || a == c || b == c))
        {
            cout << "This is a isosceles right triangle." << endl;
            return 0;
        }

        else if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
        {
            cout << "This is a right triangle." << endl;
            return 0;
        }
        
        else if (a == b || a == c || b == c)
        {
            cout << "This is a isosceles triangle." << endl;
            return 0;
        }
        
        else
        {
            cout << "This is a common triangle." << endl;
        }
    }
    else
    {
        cout << "This is not a triangle." << endl;
    }

    return 0;
}