#include<iostream>
#include<cmath>
using namespace std;

void sort_b(int b[], int n){
	int t;
	for(int i=0; i<n-1; i++){
		for(int j=i+1;j<n-1;j++){
			if(b[j]<b[j+1]){
				t=b[j];b[j]=b[j+1];b[j+1]=t;
			}
		}
	}
	
}

int isSu(int n){
	if(n<2){
		return 0;
	} else if(n==2) {
		return 1;
	} else {
		int m=sqrt(n);
		for(int i=2;i<m;i++){
			if(n%i==0){
				return 0;
			}
		}
		
		return 1;
	}
}

int main(){
	int n, k=0, a[1000], b[1000];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++){
		if(isSu(a[i])){
			b[k++]=a[i];
		}
	}
	
	sort_b(b, k-1);
	
	for(int i=0; i<k-1; i++){
		cout<<b[i]<<endl;
	}
	
	
	return 0;
} 
