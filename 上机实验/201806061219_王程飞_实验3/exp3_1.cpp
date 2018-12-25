#include <iostream>
using namespace std;

int main(){
	int n,sum,ct=0,avg[30],k;
	cin>>n;
	if(n>300){
		cout<<"超出限制"<<endl;
		return 0;
	}
	for(int i=2;i<=n;i+=10){
		sum=0;k=0;
		for(int j=0;j<=8;j+=2){
			if(i+j<=n){
				cout<<i+j<<"\t";
				k++;
				sum+=(i+j);
			}
		}
		if(k==0){
			avg[ct]=0;
			ct++;
		}else{
			avg[ct]=sum/k;
		}
		//cout<<sum/k<<endl;
		ct++;
		cout<<endl;
	}
	for(int i=0;i<ct;i++){
		cout<<"第"<<i<<"行平均数为："<<avg[i]<<endl;
	}
	
	return 0;
}
