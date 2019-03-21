#include<iostream>
using namespace std;

int main(){
	int result[100],num=0,n;
	while(cin>>num&&num>0){
		//init
		n=0;
		for(int i=0;i<100;i++){
			result[i]=0;
		}
		//process
		for(int i=0;num>0;i++){
			result[i]=num%2;
			num/=2;
			n++;
		}
		//output
		for(int i=n-1;i>=0;i--){
			cout<<result[i];
		}
		cout<<endl;
	}
	
	return 0;
}
