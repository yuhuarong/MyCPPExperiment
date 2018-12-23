#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int converts(char s[]){
	int result=0,len=strlen(s);
	for(int i=len-1;i>=0;i--){
		if(s[i]>'9'||s[i]<'0'){
			result=10001;break;
		}
		result+=(s[i]-48)*pow(10,len-i-1);
		//cout<<(s[i]-48)*pow(10,len-1-i)<<endl;
	}
	
	
	return result;
}

int main(){
	char s[5];
	int a;
	cin>>s;
	a=converts(s);
	if(a>=0&&a<10000){
		cout<<a<<endl;
	} else {
		cout<<"ÊäÈëÓÐÎó"<<endl; 
	}
	
	
	return 0;
}
