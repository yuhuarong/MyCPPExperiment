#include<iostream>
#include<string.h>
using namespace std;

void conbine(char a[], char b[]){
	int len=strlen(a);
	for(int i=0; b[i]!='\0'; i++){
		a[len+i]=b[i];
	}
	
}

int main(){
	char a[20],b[10];
	cin>>a;cin>>b;
	conbine(a,b);
	cout<<a;
	
	return 0;
}
 
