#include<iostream>
using namespace std;

struct Complex{
	int a;
	int b;
	//a+bi
}m,n;

int main(){
	char i;
	cin>>m.a>>m.b>>i;
	cin>>n.a>>n.b>>i;
	cout<<m.a+n.a<<((m.b+n.b<0)?"":"+")<<m.b+n.b<<"i"<<endl;
	
	return 0;
} 
