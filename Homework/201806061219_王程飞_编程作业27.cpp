#include<iostream>
using namespace std;

int isE(int a[100][100],int n){
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//cout<<*(*(a+i)+j)<<endl;
			if(j!=i){
				if(*(*(a+i)+j)!=0){
					return 0;
				}
			}else{
				if(*(*(a+i)+j)!=1){
					return 0;
				}
			}
		}
	}
	
	return 1;
}

int main(){
	int a[100][100],n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	cout<<(isE(a,n)?"Yes":"No")<<endl;
	
	return 0;
}
