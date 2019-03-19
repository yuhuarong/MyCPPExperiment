#include<iostream>
using namespace std;

int main(){
	int t;
	while(cin>>t){
		for(int j=t;j>0;j--){
			for(int k=0;k<j;k++){
				cout<<'*';
			}
			cout<<endl;
		}
	}
} 
