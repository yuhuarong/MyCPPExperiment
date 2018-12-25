#include<iostream>
#include<cmath>
using namespace std;

int sim(int a[], int b[], int n) {
	int sum = 0;
	for(int i=0;i<n;i++) {
		sum+=(a[i]-b[i])*(a[i]-b[i]);
	}
	
	return sum;
	
}

int main(){
	int T,a[3000][3000],b[3000],n,min;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[0][j];
		}
		for(int j=0;j<n;j++){
			cin>>b[j];
		}
		
		min=sim(a[0],b,n);
		for(int j=1;j<n;j++){
			for(int k=0;k<n;k++) {
				a[j][k]=a[0][k+j<n?k+j:abs(k+j-n)];
			}
		}
		for(int j=1;j<n;j++) {
			int t=sim(a[j],b,n);
			min=t<min?t:min;
		}
		cout<<min<<endl;
		
	}
	
	return 0;
} 
