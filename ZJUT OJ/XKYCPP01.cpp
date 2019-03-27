#include <iostream>
using namespace std;
int main(){
	int n;
	char a;
	while(cin>>a>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				cout<<" ";
			}
			for(int x=0;x<2*i+1;x++){
				cout<<a;
			}
			cout<<endl;
		}
	}
	return 0;
}

