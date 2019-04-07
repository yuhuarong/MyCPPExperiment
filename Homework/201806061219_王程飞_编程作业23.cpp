#include<iostream>
using namespace std;

void min_max_mean(int a[], int n, int *max_val, int *min_val, int *mean_val){
	int max=a[0],min=a[0],avg;
	for(int i=0;i<n;i++) {
		avg+=a[i];
		max=a[i]>max?a[i]:max;
		min=a[i]<min?a[i]:min;
	}
	avg/=n;
	*max_val=max;*min_val=min;*mean_val=avg;
}

int main(){
	
	int max,min,avg,*pmax=&max,*pmin=&min,*pavg=&avg,n,a[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	min_max_mean(a, n, pmax, pmin, pavg);
	
	cout<<"max : "<<max<<endl<<"min : "<<min<<endl<<"average : "<<avg<<endl;
	
	return 0;
} 
