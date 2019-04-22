//#include <iostream>
#include "Boolean.cpp" 
//using namespace std;

ostream& operator<< (ostream& out, const Boolean& b) {
	out << ((b.getFlag() != 0) ? "true" : "false");
	return out;
}

int main() {
	//cout << "helloworld" << endl;
	Boolean a(0), b(1.10), c(a);
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	a = true;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	a = c && b;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	a = b ^ b;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	a = c ^ b;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	a = c || b;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	b = c;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	c = Boolean(true);
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	return 0;
}
