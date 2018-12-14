#include<iostream>
using namespace std;

int myPower(int n, int k){
	if(k>0){
		return n*myPower(n,k-1);
	} else {
		return 1;
	}
}

int main(){
	int n,k;
	cin>>n>>k;
	cout<<myPower(n,k)<<endl;
	
	return 0;
} 
