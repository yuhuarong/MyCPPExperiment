#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int *p1,int *p2){
	int a;
	a=*p1;*p1=*p2;*p2=a;
}

void sort_array(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int i=0;i<n-i-1;i++){
			
		}
	}
}

int main(){
	int a[1000],n;
	cin>>n;
	for(int i=0;i<n;i++){
		a[i]=rand()%1000;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	sort_array(a,n);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
} 
