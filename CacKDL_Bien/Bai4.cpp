#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double Cau_a(double x)
{
    double y1 = 4*(x*x + 10*x*sqrt(x) + 3*x + 1);

    return y1;
}

double Cau_b(double x)
{
    double y2 = (sin(M_PI*x*x) + sqrt(x*x + 1))/(pow(M_E, 2*x) + cos(M_PI_4*x));

    return y2;
}

int main()
{
    double x;

    cout << "Nhap so thuc x: "; cin >> x;

    cout << "Dap so cau a): " << Cau_a(x) << endl;
    cout << "Dap so cau b): " << Cau_b(x) << endl;

    return 0;
}