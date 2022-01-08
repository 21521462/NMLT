#include <iostream>
#include <cmath>

using namespace std;

int PTBac2(float a, float b, float c, float &x1, float &x2)
{
    float delta = b * b - 4 * a * c;

    if (delta < 0)
    {
        x1 = x2 = 0.0;
        return 0;   
    }

    else if (delta == 0)
    {
        x1 = x2 = -b / (2 * a);
        return 1;
    }

    else
    {
        delta = sqrt(delta);
        x1 = (-b + delta) / (2 * a);
        x2 = (-b - delta) / (2 * a);
        return 2;
    }
}

int main()
{
    float x1, x2, a, b, c;

    do
    {
        cout << "Nhập a, b, c (a khác 0): "; cin >> a >> b >> c;
    } while (!a);
    

    if (PTBac2(a, b, c, x1, x2) == 0)
    {
        cout << "Phương trình vô nghiệm." << endl;
    }

    else if (PTBac2(a, b, c, x1, x2) == 1)
    {
        if (x1 > 0)
        {
            cout << "Phương trình có hai nghiệm:" << endl;
            cout << "x1 = " << sqrt(x1) << endl;
            cout << "x2 = " << -sqrt(x1) << endl;
        }

        else if (x1 == 0 )
        {
            cout << "Phương trình có một nghiệm: x = " << 0 << endl;
        }

        else
        {
            cout << "Phương trình vô nghiệm." << endl;
        }
    }
    
    else
    {
        if (x1 < 0)
        {
            if (x2 < 0)
            {
                cout << "Phương trình vô nghiệm." << endl;
            }

            else if (x2 == 0)
            {
                cout << "Phương trình có một nghiệm: x = " << 0 << endl;
            }

            else
            {
                cout << "Phương trình có hai nghiệm:" << endl;
                cout << "x1 = " << sqrt(x2) << endl;
                cout << "x2 = " << -sqrt(x2) << endl;
            }
        }

        else if (x1 == 0)
        {
            if (x2 < 0)
            {
                cout << "Phương trình có một nghiệm: x = " << 0 << endl;
            }

            else
            {
                cout <<"Phương trình có ba nghiệm:" << endl;
                cout << "x1 = " << sqrt(x2) << endl;
                cout << "x2 = " << -sqrt(x2) << endl;
                cout << "x3 = " << 0 << endl;
            }
        }

        else
        {
            if (x2 < 0)
            {
                cout << "Phương trình có hai nghiệm:" << endl;
                cout << "x1 = " << sqrt(x1) << endl;
                cout << "x2 = " << -sqrt(x1) << endl;
            }

            else if (x2 == 0)
            {
                cout << "Phương trình có ba nghiệm:" << endl;
                cout << "x1 = " << sqrt(x1) << endl;
                cout << "x2 = " << -sqrt(x1) << endl;
                cout << "x3 = " << 0 << endl;
            }
            
            else
            {
                cout << "Phương trình có bốn nghiệm:" << endl;
                cout << "x1 = " << sqrt(x1) << endl;
                cout << "x2 = " << -sqrt(x1) << endl;
                cout << "x3 = " << sqrt(x2) << endl;
                cout << "x4 = " << -sqrt(x2) << endl;
            }
        }
    }

    return 0;
}