#include<iostream>
using namespace std;

int main(){
	int a[1000],numa,numb,j,temp;
	cin>>numa;
	for(j=0;j<numa;j++){
		cin>>a[j];
	}
	cin>>numb;
	for(j=numa;j<numb+numa;j++){
		cin>>a[j];
	}
	for(int i=0;i<numa+numb;i++){
		for(int j=i+1;j<numa+numb;j++){
			if(a[j]<a[i]){
				temp=a[i];a[i]=a[j];a[j]=temp;
			}
		}
	}
	
	for(int i=0;i<numa+numb;i++){
		if(i==numa+numb-1){
			cout<<a[i]<<endl;
		}else{
			cout<<a[i]<<" ";
		}
		
	}
	return 0;
}
