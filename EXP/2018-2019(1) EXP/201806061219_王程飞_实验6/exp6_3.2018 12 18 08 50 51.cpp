#include<iostream>
using namespace std;

void fun(int a[],int *n){
	int flag,ct=0;
	for(int i=1;i<=100;i++){
		flag=0;
		if(i%7==0){
			flag++;
		}
		if(i%11==0){
			flag++;
		}
		if(flag==1){
			a[ct]=i;ct++;
			cout<<i<<endl;
		}
		
	}
	*n=ct;
}

int main(){
	int a[100],n=0;
	fun(a,&n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	//cout<<n<<endl;
	
	return 0;
}
