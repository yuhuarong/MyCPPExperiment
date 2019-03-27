#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	char a[1000],b[1000];
	do{
		gets(a);gets(b);
		sort(a,a+strlen(a));
		sort(b,b+strlen(b));
		//cout<<a<<endl;
		//cout<<b<<endl;
		if(strcmp(a,b)){
			cout<<"no"<<endl;
		} else {
			cout<<"yes"<<endl;
		}
		//cout<<strcmp(a,b)<<endl;
	}while(gets(a));
}
