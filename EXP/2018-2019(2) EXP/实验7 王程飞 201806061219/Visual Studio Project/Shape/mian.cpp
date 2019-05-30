#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"

int main()
{
	Point point(3.5, 6.4), * p;
	Circle circle(4, 5, 6), * cir;
	Cylinder cyclinder(5, 6, 8), * cyl;

	cout << point;
	cout << circle;
	cout << cyclinder;

	p = &point;
	cir = &circle;
	cyl = &cyclinder;
	cout << (*p);
	cout << (*cir);
	cout << (*cyl);

	
	cir->area();
	cir = &cyclinder;
	cir->area();

	return 0;
}
