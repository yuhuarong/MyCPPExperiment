#pragma once 
#include "Point.cpp"
using namespace std;

class Square : public Point {
public:
	Square(double x, double y, double A) :Point(x, y), a(A) {}
	friend ostream& operator<<(ostream& out, const Square& s) {
		out << "Square : " << "(" << s.getX() << "," << s.getY() << ") a = " << s.a << endl;
		return out;
	}

	double getA() {
		return a;
	}

	void setA(double a) {
		if (a > 0) {
			this->a = a;
		}
		else {
			this->a = 0;
		}
	}
	
	void modify(double delta){
		a+=delta;
	} 

private:
	double a;

};

