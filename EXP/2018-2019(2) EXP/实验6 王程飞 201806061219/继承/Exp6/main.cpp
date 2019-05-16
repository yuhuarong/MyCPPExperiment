#include "Point.h"
#include "Square.h"
#include "Circle.h"
using namespace std;

int main() {
	Point a(1.0, 2.0);
	Circle b(1.0, 2.0, 4.0);
	Square c(3.0, 5.0, 5.0);
	cout<<a;
	cout<<b;
	cout<<c;
	return 0;
}
