#include<bits/stdc++.h> 
using namespace std;

int main(){
	int n,max,ntime=0,nheavy=0,mheavy,ltime=0,lheavy=0;
	cin>>n>>max;
	cin>>ntime>>mheavy;
	lheavy=nheavy=nheavy;ltime=ntime;
	if(mheavy>max){
		nheavy=lheavy=0;
	}
	cout<<nheavy<<endl;
	for(int i=1;i<n;i++){
		cin>>ntime>>mheavy;
		int delta=ntime-ltime;
		lheavy=(lheavy-delta)>0?lheavy-delta:0;
		if(nheavy=mheavy+lheavy>max){
			nheavy=lheavy=0;
		} else {
			nheavy=(lheavy-mheavy)>0?lheavy-mheavy:0;
			
		}
		
		cout<<nheavy<<endl;
		ltime=ntime;
	}
	
	return 0;
}
