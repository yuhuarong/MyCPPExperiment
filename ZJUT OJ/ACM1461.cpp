#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int a1,a2,n,a3;
	while(cin>>a1>>a2>>n){
		for(int i=0;i<n-2;i++){
			a3=abs(a2-a1);
			a1=a2;
			a2=a3;
			//cout<<a1<<" "<<a2<<endl; 
		}
		cout<<a2<<endl;
	}
}
