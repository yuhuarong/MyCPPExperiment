#include<iostream> 
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	float x,eps,result=0,s;int n=1,f=-1;double jc=1;
	cin>>x>>eps;
	if(x<0||x>10)
	{
		cout<<"x error"<<endl;
	}
	else
	{
		do{
			f=-f;
			s=f*pow(x,n)/jc;
			jc*=((n+1)*(n+2));
			n+=2;
			result+=s;
			cout<<s<<endl;
		}while(fabs(s)>=eps);
		result=int(result*(1/eps))/ (1/eps);
		cout<<result<<endl;
	}
	
	return 0;
}
