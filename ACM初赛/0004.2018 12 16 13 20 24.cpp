#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
	int T,flag=0,posE,mpow;char a[301],sign1,sign2,result[310];
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>a;
		sign1=a[0];
		int len=strlen(a);
		flag=0;
		for(int j=0;posE=j,a[j]!='E';j++);
		//cout<<posE<<endl;
		sign2=a[posE+1];
		int powLen=0;
		for(int j=posE+1;a[j]!='\0';powLen++,j++);
		--powLen;
		for(int j=posE+1;j<posE+1+powLen;j++){
			mpow+=(a[j]-48)*pow(10,posE+1+powLen-j);
			cout<<posE+1+powLen-j<<endl;
		}
		cout<<mpow<<endl;
		
		
	}
	
	return 0;
}
