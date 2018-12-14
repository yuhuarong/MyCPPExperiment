#include<iostream>
#include<cmath>
using namespace std;

int wanZhengShu(int n){
	int k=n/2;int sum=0;
	for(int i=1;i<=k;i++){
		sum+=((n%i==0)?i:0);
		
	}
	
	//cout<<n<<" "<<sum<<endl;
	if(sum==n){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	for(int i=1;i<=10000;i++){
		if (wanZhengShu(i)){
			cout<<i<<endl;
		}
	}
	return 0;
}
