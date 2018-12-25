#include<iostream>
using namespace std;

int main(){
	int T,n,a[1000],b[1000],time;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j];
		}
		time=a[0];
		for(int j=0;j<n;j++){
			if(time<a[j]){
				time=a[j];
			}
			
			if((b[j]-time+a[j])>0){
				cout<<time<<" ";
				time++;
			} else {
				cout<<0<<" ";
			}
			
		}
		
		cout<<endl;
		
	}
	
	return 0;
}
