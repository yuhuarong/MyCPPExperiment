#include <iostream>
using namespace std;

int func()
{
	static int n=0;
	
	return n=n+1;
	
}

int main()
{
	int a,s=1;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		s*=func();
	}
	cout<<s<<endl;
	
	return 0;
} 
