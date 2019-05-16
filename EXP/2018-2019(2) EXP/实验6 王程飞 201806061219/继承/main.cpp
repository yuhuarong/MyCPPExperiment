#include<iostream>
using namespace std;

class Point {
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double getX() const {
		return x;
	}

	double getY() const {
		return y;
	}

	void setX(double x) {
		this->x = x;
	}

	void setY(double y) {
		this->y = y;
	}

	void moveTo(double x, double y) {
		this->x = x;
		this->y = y;
	}

	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "Point : " << "(" << p.x << "," << p.y << ")" << endl;
		return out;
	}

private:
	double x;
	double y;
};

class Circle : public Point {
public:
	Circle(double x, double y, double r) :Point(x, y), radius(r) {}
	friend ostream& operator<<(ostream& out, const Circle& c) {
		out << "Circle : " << "(" << c.getX() << "," << c.getY() << ") radius = " << c.radius << endl;
		return out;
	}

	double getRadius() {
		return radius;
	}

	void setRadius(double r) {
		if (r > 0) {
			radius = r;
		}
		else {
			radius = 0;
		}
	}
	
	void modify(double delta){
		radius+=delta;
	} 
private:
	double radius;
};

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


int main() {
	Point a(1.5, 2.8);
	cout<<a;
	a.moveTo(5.7, 9.5);
	cout<<a;
	Circle b(1.2, 2.5, 4.0);
	cout<<b;
	b.moveTo(1.3, 3.6);
	cout<<b; 
	b.modify(-1);
	cout<<b;
	Square c(3.7, 5.9, 5);
	cout<<c;
	c.moveTo(2.5, 5.9);
	cout<<c; 
	c.modify(8);
	cout<<c; 
	return 0;
}
