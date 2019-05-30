#pragma once
#include "Circle.h"
class Cylinder:public Circle {
public:
	Cylinder (float x=0,float y=0,float r=0,float h=0);
	float getHeight()const{return  height;}
	void setHeight(float);
	virtual float area() const;
	virtual float volume() const;
	virtual void shapeName() const { cout<<"Cylinder:";} 
	friend ostream& operator<<(ostream&, const Cylinder&);
protected:
    float height; 
};
