#include<iostream>
using namespace std;

int main()
{
	int a,b,c,m,n,ct=0;
	cin>>m>>n;
	for(int i=m;i<=n;i++)
	{
		a=i%10;
		b=(i/10)%10;
		c=i/100;
		if(a*a*a+b*b*b+c*c*c==i)
		{
			ct++;
			cout<<i<<" ";
		}
	}
	
	if(ct==0){
		cout<<"no"<<endl;
	}else{
		cout<<endl;
	}
	
	return 0;
}
