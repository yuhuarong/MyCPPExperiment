#include<iostream>
using namespace std;

void cut(char *pa,char *pb,int n){
	
	for(pa=pa+n;*pa!='\0';pa++,pb++){
		*pb=*pa;
	}
	*pb=*pa;
}

int main(){
	char a[100],b[100];int n;
	cin>>a;
	cin>>n;
	char *pa;
	char *pb=b;
	cut(a,b,n);
	cout<<b;
	
	return 0;
}
