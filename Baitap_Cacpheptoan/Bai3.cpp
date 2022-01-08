#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int r;

    cout << "Nhap ban kinh r: "; cin >> r;

    double cv = 2*M_PI*r;
    double dt = M_PI*r*r;

    cout << "Chu vi duong tron: " << cv << endl;
    cout << "Dien tich duong tron: " << dt << endl;

    return 0;
}