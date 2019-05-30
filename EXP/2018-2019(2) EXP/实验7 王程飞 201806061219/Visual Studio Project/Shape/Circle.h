#pragma once
//ÉùÃ÷CircleÀà
#include "Point.h"
class Circle:public Point {
public:
   Circle(float x=0,float y=0,float r=0);
   void setRadius(float);
   float getRadius() const;
   virtual float area() const;
   virtual void shapeName() const { cout << "Circle:"; }
   friend ostream& operator<<(ostream&, const Circle&);
protected:
   float radius;
};

Circle::Circle(float a, float b, float r) :Point(a, b), radius(r) {}

void Circle::setRadius(float r) { radius = r; }

float Circle::getRadius() const { return radius; }

float Circle::area() const { return 3.14159* radius* radius; }

ostream& operator<<(ostream& output, const Circle& c) {
	output << "[" << c.getX() << "," << c.getY() << "], r=" << c.getRadius() << endl;
	return output;
}
