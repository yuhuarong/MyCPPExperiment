#include<iostream>
using namespace std;

int main(){
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		int j;
		for(j=1;j<=a-2;j+=2){
			cout<<j<<" ";
		}
		cout<<j<<endl;
		for(j=2;j<=a-2;j+=2){
			cout<<j<<" ";
		}
		cout<<j<<endl;
	}
		
}
