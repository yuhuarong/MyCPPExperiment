#include<iostream>
using namespace std;

int main(){
	int a,b,sum;
	while(cin>>a>>b){
		sum=a+b;
		sum=sum-(sum/10)*10;
		cout<<sum<<endl;
	} 
	return 0;
} 
