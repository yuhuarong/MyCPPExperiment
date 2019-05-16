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

