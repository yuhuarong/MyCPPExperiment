#include<iostream>
using namespace std;

int my_strcmp(char *str1, char *str2){
	for(int i=0;*str1==*str2&&*str1!='\0'&&*str2!='\0';i++,str1++,str2++);
	if(*(str1)==*(str2)&&*(str2)=='\0'){
		return 0;
	}else if(*(str1)=='\0'){
		return -*(str2);
	}else if(*(str2)=='\0'){
		return *(str1);
	}else{
		return *(str1)-*(str2);
	}
	
}

int main(){
	char a[100],b[100];
	cin>>a>>b;
	cout<<my_strcmp(a,b)<<endl;
	
	return 0;
}
