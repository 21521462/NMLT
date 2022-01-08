#include <iostream>

using namespace std;

int main()
{
    float a, b;

    cout << "Enter a, b: "; cin >> a >> b;

    if (a == 0)
    {
        if (b == 0)
        {
            cout << "Experience countless equations." << endl;
        }
        else
        {
            cout <<"No experimental equation." << endl;
        }
    }
    else
    {
        cout << "The equation has a solution is: " << -b/a << endl;
    }

    return 0;
}