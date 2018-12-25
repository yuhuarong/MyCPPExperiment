#include<iostream>
using namespace std;

int main(){
	string a;
	int flag;
	//cout<<a.length()<<endl;
	while(cin>>a&&a!="0"){
		//cout<<a<<endl;
		flag=1;
		for(int i=0;i<a.length()/2;i++){
			if(a[i]==a[a.length()-i-1]){
				flag=1;
			}else{
				flag=0;break;
			}
		}
		cout<<(flag==0?"No":"Yes")<<endl;
	}
	
	return 0;
} 
