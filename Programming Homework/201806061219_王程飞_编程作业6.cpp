#include<iostream>
using namespace std;

int main()
{
	int a[10],n=0;
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<10;i++)
	{
		if(a[i]%3==0){
			n++;
		}
	}
	cout<<n<<endl;
	
	return 0;	
}
