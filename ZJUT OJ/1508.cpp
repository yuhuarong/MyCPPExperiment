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
	int a, b;
	while(cin>>a>>b&&a!=0&b!=0){
		cout<<gcd(a,b)+a*b/gcd(a,b)<<endl;
	}
} 
