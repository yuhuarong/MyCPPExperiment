#include<iostream>
using namespace std;

int main(){
	int a[10];
	//input ten num here
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	//output
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
	
	return 0; 
} 
