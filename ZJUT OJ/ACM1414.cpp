#include<iostream>
#include<algorithm>
using namespace std;

int compare(int a,int b){
	return a<b;
}

int main(){
	int n,a[100];
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n,compare);
		for(int i=0;i<n-1;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[n-1]<<endl;
	}
}
