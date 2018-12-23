#include<iostream>
using namespace std;

int main(){
	int n,m,t,y,w,area=1,len=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>t;
		if(t==1){
			cin>>y>>w;
			area++;len+=w;
		} else if(t==2) {
			cout<<area<<" "<<len<<endl;
		}
	}
	
	return 0;
}
