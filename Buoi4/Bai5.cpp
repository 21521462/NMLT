#include <iostream>

using namespace std;

int main()
{
	int S = 0;

	for (int i = 3; i < 1000; i++)
    {
		if (i % 3 == 0 || i % 5 == 0)
        {
            S = S + i;
        }
	}

	cout << "Tong cac boi so: " << S << endl;

    return 0;
}