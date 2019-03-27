#include<iostream>
using namespace std;

int main(){
	char a[1000];
	while(gets(a)){
		for(int i=0;a[i]!='\0';i++){
			if(a[i]>='a'&&a[i]<='z'){
				cout<<char(a[i]-32);
			}else if(a[i]>='A'&&a[i]<='Z'){
				cout<<char(a[i]+32);
			}else{
				cout<<a[i];
			}
		}
		cout<<endl; 
	}
}
