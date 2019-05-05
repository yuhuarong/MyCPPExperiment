#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,sum;
	char a[10][4];
	while(cin>>n&&n!=0){
		sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<4;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			sort(a[i]+0,a[i]+4);
			int b=a[i][0];int c=0;
			for(int j=0;j<4;j++){
				//cout<<a[i][j];
				if(a[i][j]==b){
					c++;
					if(c%2==0){
						sum+=c/2;
						c=0;
					} 
				}else{
					b=a[i][j];
					c=1;
				} 
			} 
		}
		cout<<sum<<endl;
	}
}
