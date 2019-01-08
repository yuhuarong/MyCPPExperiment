#include<iostream>
#include<cstring>
using namespace std;

int main(){
	
	int flag=0,n;char a[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;flag=1;
		for(int j=0;j<strlen(a)/2;j++){
			if(a[j]!=a[strlen(a)-1-j]){
				flag=0;break;
			}
		}
		if(flag){
			cout<<"yes"<<endl;
		} else {
			cout<<"no"<<endl;
		}
	}
	
	return 0;
}
