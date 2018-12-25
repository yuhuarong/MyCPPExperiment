#include <iostream>
using namespace std;

int main(){
	char a[1000],c;
	gets(a);
	cin>>c;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]==c){
			a[i]='\n';
		}
		
	}
	cout<<a<<endl;
	
	return 0;
}
