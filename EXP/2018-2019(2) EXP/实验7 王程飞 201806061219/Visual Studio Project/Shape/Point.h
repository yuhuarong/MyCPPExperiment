#pragma once

#include "Shape.h"
class Point:public Shape { //Point是Shape的公用派生类
public:
	Point(float=0,float=0);
	void setPoint(float,float);
	float getX() const {return x;}
	float getY() const {return y;}
	virtual void shapeName() const { cout<<"Point:";} 
	friend ostream& operator<<(ostream&,const Point &);
protected:
	float x,y;   
};