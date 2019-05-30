#include <iostream>
#include "Vehicle.h"
#include "Taxi.h"
#include "Trunk.h"
using namespace std;

int main()
{
	Vehicle v(2, 6, 3, "blue", 14.6);
	cout << v << endl;
	Taxi t(4, 6, 5, "yellow", 3.3, 0);
	cout << t << endl;
	Trunk r(4, 6, 5, "black", 3.3, 1);
	cout << r << endl;
}
