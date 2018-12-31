#include<iostream>
using namespace std;
struct complex
{
	int a;
	int i;
}; 
int main()
{
	struct complex a,b,c;
	cin>>a.a>>a.i>>b.a>>b.i;
	c.a=a.a+b.a;
	c.i=a.i+b.i;
	cout<<c.a<<"+"<<c.i<<'i';
	return 0;
}
