#include<iostream>
using namespace std;

int main(){
	char k;int n,m,sum=0;
	while(cin>>m>>k>>n){
		if(k=='b'){
			if(n>=11&&n<=17){
				sum+=m;
			} else {
				sum-=m;
			}
		} else {
			if(n>=4&&n<=10){
				sum+=m;
			} else {
				sum-=m;
			}
		} 
	}
	cout<<sum<<endl;
}
