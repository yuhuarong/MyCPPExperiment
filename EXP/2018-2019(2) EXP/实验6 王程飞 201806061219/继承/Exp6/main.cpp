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
		out << "Point : " << "(" << p.x << ", " << p.y << ")" << endl;
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
		out << "Circle : " << "(" << c.Point::getX() << ", " << c.Point::getY() << ") radius = " << c.radius << endl;
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
private:
	double radius;
};

class Square : public Point {
public:
	Square(double x, double y, double A) :Point(x, y), a(A) {}
	friend ostream& operator<<(ostream& out, const Square& s) {
		out << "Square : " << "(" << s.Point::getX() << ", " << s.Point::getY() << ") a = " << s.a << endl;
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

private:
	double a;

};



int main() {
	Point a(1.0, 2.0);
	Circle b(1.0, 2.0, 4.0);
	Square c(3.0, 5.0, 5.0);
	cout<<a;
	cout<<b;
	cout<<c;
	return 0;
}
