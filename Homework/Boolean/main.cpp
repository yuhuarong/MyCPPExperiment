#include "Boolean.h"

int main() {
	Boolean a(0), b(1.10), c(a);
	int n=a;
	cout<<"n: "<<n<<endl;
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
