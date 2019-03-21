#include<iostream>
#include<cmath>
using namespace std;

float getItem(int n){
	return pow(-1,n+1)/((n)*(n+1));
}

int main(){
	int n;float sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		sum+=getItem(i);
	}
	cout<<sum<<endl;
	
	return 0;
}
