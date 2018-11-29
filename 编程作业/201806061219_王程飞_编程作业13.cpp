#include <iostream> 
#include<string.h>
using namespace std;

int main(){
	char str[100];
	cin>>str;
	int flag=1;
	for(int i=0;i<strlen(str)/2;i++){
		if(str[i]!=str[strlen(str)-i-1]){
			flag=0;break;
		}
	}
	
	if(flag){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl; 
	}
	
	return 0;
}
