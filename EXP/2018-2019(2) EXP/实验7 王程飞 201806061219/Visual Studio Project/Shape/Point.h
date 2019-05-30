#pragma once

#include "Shape.h"
class Point:public Shape {
public:
	Point(float=0,float=0);
	void setPoint(float,float);
	float getX() const {return x;}
	float getY() const {return y;}
	virtual void shapeName() const { cout<<"Point:";} 
	//virtual float area() const { return 0; }
	friend ostream& operator<<(ostream&,const Point &);
protected:
	float x,y;   
};

Point::Point(float a, float b) {
	x = a;
	y = b;
}
void Point::setPoint(float a, float b) {
	x = a;
	y = b;
}
ostream& operator<<(ostream& output, const Point& p) {
	output << "[" << p.getX() << "," << p.getY() << "]" << endl;
	return output;
}