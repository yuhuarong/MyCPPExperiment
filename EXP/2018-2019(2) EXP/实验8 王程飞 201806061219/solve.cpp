#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double a, b, c;
	cout << "请输入a b c :" << endl;
	cin >> a >> b >> c;
	double delta = b * b - 4 * a * c;
	int x1, x2;
	try {
		if (delta < 0) {
			throw delta;
		}
		x1 = (-b + sqrt(delta)) / 2 * a;
		x2 = (-b - sqrt(delta)) / 2 * a;
		cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	} catch (double) {
		cout << "没有实根"<<endl;
	}

}

