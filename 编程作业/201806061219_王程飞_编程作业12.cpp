#include<iostream>
using namespace std;

int change(char c)
{
	if(c>=100&&c<=122)
	{
		return c-3;
	}
	else if(c>=97&&c<=99)
	{
		return c+23;
	}
	else if(c>=65&&c<=87)
	{
		return c+3;
	}
	else if(c>=88&&c<=90)
	{
		return c-23;
	}
	else
	{
		return c;
	}
}

int main()
{
	char s[1000];
	cin>>s;
	for(int i=0;s[i]!='\0';i++)
	{
		s[i]=change(s[i]);
	}
	cout<<s<<endl;
	
	return 0;
}
