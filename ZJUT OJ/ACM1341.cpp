#include<iostream>
using namespace std;

int main(){
	int n=0;
	while(cin>>n){
		for(int t=0;t<n;t++){
			int a=0;int b;char c='a';
			for(int i=0;i<5;i++){
				cin>>b;
				a+=b;
			}
			a%=26;
			c+=a;
			cout<<c<<endl;
		}
	}
	
	return 0;
} 
