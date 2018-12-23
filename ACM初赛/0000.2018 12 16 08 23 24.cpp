#include<bits/stdc++.h> 
using namespace std;

int main(){
	int n,max,ntime=0,nheavy=0,mheavy,ltime=0,lheavy=0;
	cin>>n>max;
	cin>>ntime>>mheavy;
	lheavy=nheavy=nheavy;ltime=ntime;
	if(mheavy>max){
		mheavy=lheavy=0;
	}
	for(int i=1;i<n;i++){
		cin>>ntime>>mheavy;
		int deltaTime=ntime-ltime;
		if(nheavy=mheavy+lheavy>max){
			lhea
		}
	}
	
	return 0;
}
