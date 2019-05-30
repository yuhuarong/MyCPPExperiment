#pragma once
//ÉùÃ÷CircleÀà
#include "Point.h"
class Circle:public Point {
public:
   Circle(float x=0,float y=0,float r=0);
   void setRadius(float);
   float getRadius() const;
   float area() const;
   virtual void shapeName() const {cout<<"Circle:";}
   friend ostream& operator<<(ostream&,const Circle &);
protected:
   float radius;
};
