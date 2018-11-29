#include<iostream>
using namespace std;

int main()
{
	int n,m,a[1000],b[1000],ct=0;
	
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i]==b[j]){
				cout<<a[i]<<" ";
				ct++;
			}
		}
	}
	if(ct==0){
		cout<<"NO";
	}
	cout<<endl;
	
	return 0;
}
