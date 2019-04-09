#include<iostream>
using namespace std;

int main(){
	int n,a[100],b;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cin>>b;
		int flag=0;
		for(int i=0;i<n;i++){
			if(a[i]==b){
				flag=1;continue;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}
