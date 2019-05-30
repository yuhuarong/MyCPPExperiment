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

Cylinder::Cylinder(float x, float y, float r, float h) :Circle(x, y, r), height(h) {}

void Cylinder::setHeight(float h) { 
	height = h; 
}

float Cylinder::area() const { 
	return 2 * Circle::area() + 2 * 3.14159 * radius * height;
}

float Cylinder::volume() const { 
	return Circle::area()* height;
}

ostream& operator<<(ostream& output, const Cylinder& cy) {
	output << "[" << cy.getX() << "," << cy.getY() << "], r=" << cy.getRadius() << ", h=" << cy.getHeight() << endl;
	return output;
}

