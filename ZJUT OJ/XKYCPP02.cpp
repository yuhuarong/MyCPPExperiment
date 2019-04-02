#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int a[1000],x,r,f;
	int n,m;
	while(cin>>n>>m&&n!=0||m!=0){
		f=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<m;i++){
			cin>>x;
			for(int j=0;j<n;j++){
				if(a[j]==x){
					a[j]=-2334546;
					f++;
				}
			}
		}
		r=0;
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(a[i]!=-2334546){
				r++;
				cout<<a[i];
				if(r<n-f){
					cout<<" ";
				}
			}
		}
		if(r==0){
			cout<<"NULL";
		}
		cout<<endl;
	}
}
