#include <iostream>
using namespace std;
int main()
{
	int num;
	int add=0;
	int i=0;
	while(cin>>num)
	{
		int *a;
		a=new int[num];
		if(num==0)break;
		else for(i=0;i<num;i++)
		    {
		    	int a,b,c,d;
			    cin>>a;cin>>b;cin>>c;cin>>d;
			    if(((a==b)&&(c==d))||((a==c)&&(b==d))||((a==d)&&(b==c))) a[i]=2;
		        else if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d) a[i]=0;
		        else a[i]=1;
		    }
		for(int i=0;i<num;i++)
		{add=add+a[i];}
		delete []a;	
	}
	cout<<add<<endl;
	return 0;
 } 
