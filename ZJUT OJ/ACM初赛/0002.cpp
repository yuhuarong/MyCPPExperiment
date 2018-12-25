#include<iostream>
using namespace std;

int main(){
	int n,m,t,y,w,area=1,len=0,flag[100000]={0};
	cin>>n>>m;
	flag[1]=1;
	for(int i=0;i<m;i++){
		cin>>t;
		if(t==1){
			cin>>y>>w;
			if(flag[y]){
				
			} else {
				flag[y]=1;
				area++;
			}
			len+=w;
		} else if(t==2) {
			cout<<area<<" "<<len<<endl;
		}
	}
	
	return 0;
}
