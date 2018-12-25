#include<iostream>
using namespace std;

int main(){
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=1;j<=k-1;j+=2){
			if(j==k-1){
				cout<<j<<endl;
			}else{
				cout<<j<<" "; 
			}
		}
		for(int j=2;j<=k;j+=2){
			if(j==k){
				cout<<j<<endl;
			}else{
				cout<<j<<" "; 
			}
		}
	}
	
	return 0;
}
