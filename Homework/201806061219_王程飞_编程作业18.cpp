#include<iostream>
#include<string.h>
using namespace std;

char change(char c){
	if(c>='a'&&c<='z'){
		return c-32;
	}else if(c>='A'&&c<='Z'){
		return c+32;
	}else{
		return c;
	}
}

int main(){
	char a[1000];
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		a[i]=change(a[i]);
	}
	cout<<a<<endl;
	
	return 0;
}
