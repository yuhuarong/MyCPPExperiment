#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char a[1000];int n,t;
	while(cin>>a>>n){
		t=0;
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				cout<<a[(j+t)%strlen(a)];
			}
			cout<<endl;
			if(t++==n){t=0;}
		}
		cout<<endl;
		
	}
	
	return 0;
}
