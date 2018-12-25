#include<iostream>
using namespace std;
int calc_sum(int (*p)[3]){
	return **p+*(*p+1)+*(*p+2);
}

int main(){
	int a[3][3],sum[3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
		*(sum+i)=calc_sum(&a[i]);
		
	}
	
	for(int i=0;i<3;i++){
		cout<<*(sum+i)<<endl;
	}
	
	
	return 0;	
}
