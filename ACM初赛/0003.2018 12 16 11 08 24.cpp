#include<iostream>
using namespace std;

int main(){
	int T,n,a[5000],b[5000],time; 
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
				cout<<time;
			} else {
				cout<<0;
				time--;
			}
			if(j!=n-1){
				cout<<" ";
			}
			time++;
		}
		cout<<endl;
		
	}
	
	return 0;
}
