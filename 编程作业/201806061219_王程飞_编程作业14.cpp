#include <iostream>
using namespace std;

int main(){
	int a[100][100];int m,n;int isxMax[100][100],isyMin[100][100];
	cout<<"请输入行和列"<<endl;
	
	cin>>m>>n;
	cout<<"请按行输入数字"<<endl; 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			isxMax[i][j]=1;isyMin[i][j]=1;
		}
	} 
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(a[i][j]<a[k][j]){
					isxMax[i][j]=0;
					break;
				}
			} 
			for(int k=0;k<n;k++){
				if(a[i][j]>a[i][k]){
					isyMin[i][j]=0;
					break;
				}
			} 
		}
	} 
	int ct=0; 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(isxMax[i][j]&&isyMin[i][j]){
				cout<<i+1<<" "<<j+1<<endl;
				ct++;
			}
		}
	}
	
	if(!ct){
		cout<<"不存在"<<endl;
	}
	
	return 0;
}
