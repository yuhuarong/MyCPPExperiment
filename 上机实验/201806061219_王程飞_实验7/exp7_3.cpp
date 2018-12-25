#include<iostream>
using namespace std;

int main(){
	char a[100];
	cin>>a;
	
	char *pa=a;
	while(*pa!='\0'){
		if(*pa>='0'&&*pa<='9'){
			//cout<<'!';
			char *pb=pa;
			while(*pb!='\0'){
				//cout<<*pb;
				*pb=*(pb+1);
				pb++;
			}
			
		} else {
			pa++;
		}
	}
	
	cout<<a<<endl;
	
	return 0;
}
