#include<iostream>
#include<string.h> 
using namespace std;

int main(){
	char a[1000];
	cin>>a;
	cout<<a;
	for(int i=0;i<strlen(a);i++){
		cout<<a[strlen(a)-1-i];
	}
	
	return 0;
}
