#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"

int main()
{
	Point point(3.5, 6.4), * p;
	Circle circle(4, 5, 6), * cir;
	Cylinder cyclinder(5, 6, 8), * cyl;

	cout << point << endl;
	cout << circle << endl;
	cout << cyclinder << endl;

	p = &point;
	cir = &circle;
	cyl = &cyclinder;
	cout << (*p) << endl;
	cout << (*cir) << endl;
	cout << (*cyl) << endl;
	
	cout << cir->area() << endl;
	cir = &cyclinder;
	cout << cir->area() << endl;

	p = &circle;
	cout << p->area() << endl;
	p = &cyclinder;
	cout << p->area() << endl;
	Point& p1 = circle;
	cout << p1.area() << endl;
	Point& p2 = cyclinder;
	cout << p2.area() << endl;

	return 0;
}
