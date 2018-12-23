#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,x,y,min,n,x[10],y[10],rec[10],char route[100000],time[10]={0};
	cin>>T;
	for(int i=0;i<T;++i){
		cin>>x>>y>>min>>n;
		for(int j=0;j<n;++j){
			cin>>x[j]>>y[j]>>rec[y]>>route;
			for(int k=0;route[k]!='\0';++k){
				if(rec[j]<min){
					time[j]=-1;break;
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
			
			sort()
			
			
		}
	}
	
	
	return 0;
}
