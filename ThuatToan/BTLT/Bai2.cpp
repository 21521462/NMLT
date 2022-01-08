#include <iostream>

using namespace std;

int main()
{
    float a, b;

    cout << "Enter a, b: "; cin >> a >> b;

    if (a == 0)
    {
        if (b >= 0)
        {
            cout << "Countless solution." << endl;
        }
        else
        {
            cout << "No solution." << endl;
        }
    }
    else
    {
        cout << "The solution of the inequality is x >= " << -b/a;
    }

    return 0;
}