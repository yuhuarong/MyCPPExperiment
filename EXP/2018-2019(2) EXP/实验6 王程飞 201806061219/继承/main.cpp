#include <iostream>
#include "Square.cpp"
#include "Circle.cpp"
using namespace std;

int main() {
	Point a(1, 2);
	Circle b(1, 2, 4);
	Square c(2, 5, 5);
	cout<<a;
	cout<<b;
	cout<<c;
	return 0;
}
