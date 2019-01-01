#include<iostream>
using namespace std;

int main()
{
	int a,b;
	
	cin>>a>>b;
	
	if(a>=b)
	{
		if(a==b)
		{
			cout<<a<<"dengyu"<<b<<endl;
		}
		else
		{
			cout<<a<<"dayu"<<b<<endl;
		}
		
	}
	else
	{
		cout<<a<<"xiaoyu"<<b<<endl;
	}
	
	return 0;
} 
