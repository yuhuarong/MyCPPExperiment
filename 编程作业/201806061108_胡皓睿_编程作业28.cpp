#include<iostream>
#include<cstring>
using namespace std;
struct complex
{
	int a;
	int i;
}; 
int main()
{
	struct complex a,b,c;
	char n1[100],n2[100];
	int l1,l2,f1,f2,w1,w2,nw1,nw2,k;
	a.a=0;
	a.i=0;
	b.a=0;
	b.i=0;
	cin>>n1>>n2;
	l1=strlen(n1);
	l2=strlen(n2);
	for (int x=0;x<l1;x++)
	{
		if (n1[x]=='+')
		{
			f1=x;
			w1=1;
		}
		if (n1[x]=='-')
		{
			f1=x;
			w1=-1;
		}
	}	
	for (int x=0;x<l2;x++)
	{
		if (n2[x]=='+')
		{
			f2=x;
			w2=1;
		}
		if (n2[x]=='-')
		{
			f2=x;
			w2=-1;
		}
	}	
	if (n1[0]=='-')
	{
		k=1;
		w1=-1;
	} 
	else
	{
		k=0;
		w1=1;
	}
	for (int x=k;x<f1;x++)
		a.a=a.a*10+n1[x]-'0';
	a.a*=w1;
	if (n2[0]=='-')
	{
		k=1;
		w2=-1;
	} 
	else
	{
		k=0;
		w2=1;
	}
	for (int x=0;x<f2;x++)
		b.a=b.a*10+n2[x]-'0';
	b.a*=w2;
	for (int x=f1+1;x<l1-1;x++)
		a.i=a.i*10+n1[x]-'0';
	if (n1[l1-1]=='i') a.i=1;
	a.i*=w1;
	for (int x=f2+1;x<l2-1;x++)
		b.i=b.i*10+n2[x]-'0';
	if (n2[l2-1]=='i') b.i=1;
	b.i*=w2;
	c.a=a.a+b.a;
	c.i=a.i+b.i;
	if (c.i>0)
		cout<<c.a<<"+"<<c.i<<'i';
	else if (c.i<0)
		cout<<c.a<<"-"<<-c.i<<'i';
	else
		cout<<c.a;
	return 0;
}

