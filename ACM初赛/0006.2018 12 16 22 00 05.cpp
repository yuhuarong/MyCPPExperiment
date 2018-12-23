#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,x,y,min,n,x[10],y[10],rec[10],istmin[10];char route[100000],time[10]={0};
	cin>>T;
	for(int i=0;i<T;++i){
		cin>>x>>y>>min>>n;
		for(int j=0;j<n;++j){
			istmin[j]=0;
			cin>>x[j]>>y[j]>>rec[y]>>route;
			for(int k=0;route[k]!='\0';++k){
				if(rec[j]<min){
					time[j]=100000001;break;
				}
				
				if(x[j]==x&&y[j]==y){
					break;
				}
				switch(route[k]){
					case 'U':
						++y[j];
						break;
					case 'D':
						--y[j];
						break;
					case 'L':
						--x[j];
						break;	
					case 'R':
						++x[j];
						break;	
				}
				time[j]++;
			}
			
			int min=time[0],ishmax=-1;
			for(int k=1;k<n;k++){
				min=time[k]<min?time[k];
			}
			for(int k=0;k<n;k++){
				if(time[k]==min&&ishmax==-1){
					ishmax=k;
				}else{
					ishmax=
				}
			}
			
			
		}
	}
	
	
	return 0;
}
