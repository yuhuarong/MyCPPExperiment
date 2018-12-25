#include<iostream>
using namespace std;

int main(){
	int T,n,a[1000],b[1000],result[1000],time=1; 
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j];
		}
		time=1;
		for(int j=0;j<n;j++){
			if((b[j]+time-a[j])>0){
				cout<<time<<" ";
			} else {
				cout<<0<<" ";
				time--;
			}
			
			time++;
		}
		cout<<endl;
		
	}
	
	return 0;
}
