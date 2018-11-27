//Íõ³Ì·É exp4_2
#include <iostream>
using namespace std;

int main(){
	int a[2][2],b[2][2],result[2][2],sum;
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>b[i][j];
		}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			sum=0;
			for(int k=0;k<2;k++){
				sum+=a[i][k]*b[k][j];
			}
			result[i][j]=sum;
		}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 
