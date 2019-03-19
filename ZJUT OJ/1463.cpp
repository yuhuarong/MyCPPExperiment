#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(a>b)
		return gcd(a-b, b);
	else if(a<b)
		return gcd(a, b-a);
	else
		return a;
}

int main(){
	int a,b,c;
	while(cin>>a>>b>>c){
		cout<<gcd(a,gcd(b,c))<<endl;
	}
	
	return 0;
}
