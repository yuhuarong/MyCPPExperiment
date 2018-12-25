#include<iostream>
using namespace std;

int main(){
	int a[3][3],max[3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<3;i++){
		int (*b)[3]=a+i;
		max[i]=**b;
		//cout<<max[i]<<endl;
		for(int j=0;j<3;j++){
			//cout<<*(*b+j)<<endl;
			if(*(*b+j)>max[i]){
				max[i]=*(*b+j);
			}
		} 
		cout<<max[i]<<endl;
	}
	
	return 0;
}
