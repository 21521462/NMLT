#include <iostream>

using namespace std;

void tamGiac(float a, float b, float c)
{
    if (a < b + c && b < a + c && c < a + b)
    {
        cout << "a, b, c là 3 cạnh của một tam giác.\n";
    }
    else
    {
        cout << "a, b, c không là 3 cạnh của một tam giác.\n";
    }
}

int main()
{
    float a, b, c;

    do
    {
        cout << "Nhập a, b, c dương: "; cin >> a >> b >> c;
    } while (a <= 0 || b <= 0 || c <= 0);
    

    tamGiac(a, b, c);

    return 0;
}