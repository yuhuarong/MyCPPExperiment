#include<iostream>
using namespace std;

int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int b[10];
	int (*pa)[10]=&a;
	int (*pb)[10]=&b;
	int m;
	cin>>m;
	for(int i=0;i<10;i++){
		if(i+m<10){
			*(*pb+i+m)=*(*pa+i);
		} else {
			*(*pb+i+m-10)=*(*pa+i);
		}
	}
	
	for(int i=0;i<10;i++){
		*(*pa+i)=*(*pb+i);
		cout<<*(*pa+i)<<" ";
	}
	cout<<endl;
	
	return 0;
}
