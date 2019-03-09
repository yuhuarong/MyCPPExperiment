#include<iostream>
using namespace std;

int main()
{
	int num=0,a[1000],n=0;
	int c=479001600;
	while(cin>>a[n]){
		n++;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]*a[j]==c){
				num++;
			}
		}
	}
	cout<<num<<endl;
	
	return 0;
}
