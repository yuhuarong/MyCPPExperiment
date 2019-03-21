#include<iostream>
#include<cmath>
using namespace std;

int isFullSqrt(int n){
	if(((int)sqrt(n)*(int)sqrt(n))==n){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int n;
	cout<<"这个数是："<<endl;
	
	for(int i=1; i<=1000; i++){
		if(isFullSqrt(i+100)&&isFullSqrt(i+168)){
			cout<<i<<" ";
		}
	}
	
	cout<<endl;
	 
	return 0;
}
