#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,mx,my,min,n,x[10],y[10],rec[10],istmin[10];char route[100000],time[10]={0};
	cin>>T;
	for(int i=0;i<T;++i){
		cin>>mx>>my>>min>>n;
		for(int j=0;j<n;++j){
			istmin[j]=0;
			cin>>x[j]>>y[j]>>rec[j]>>route;
			for(int k=0;route[k]!='\0';++k){
				if(rec[j]<min){
					time[j]=-1;break;
				}
				
				if(x[j]==mx&&y[j]==my){
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
			
			int min=-1,hmax=-1;
			for(int k=1;k<n;k++){
				if(time[k]>=0&&min==-1){
					min=time[k];
				}else if(time[k]>0){
					min=time[k]<min?time[k]:min;
				}
				
			}
			for(int k=0;k<n;k++){
				if(time[k]==min&&hmax==-1){
					hmax=k;
				}else{
					hmax=rec[k]>rec[hmax]?k:hmax;
				}
			}
			
			cout<<++hmax<<endl;
			
		}
	}
	
	
	return 0;
}
