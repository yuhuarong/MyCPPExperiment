#include<iostream> 
using namespace std;

int main(){
	int n,h,z,t;
	while(cin>>n>>h>>z){
		t=(z-2*h)/2;
		if(n>t/2&&n<t){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
		//t/2<t<t
	}
} 
