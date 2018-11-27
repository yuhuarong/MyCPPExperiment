//Íõ³Ì·É exp4_3
#include <iostream>
using namespace std;

int main(){
	int m,n;
	int a[100][100];
	int max,index_x,index_y;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	} 
	
	max=a[0][0];index_x=0;index_y=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max){
				max=a[i][j];
				index_x=i;index_y=j;
			}
		}
	} 
	cout<<max<<endl;
	cout<<index_x<<" "<<index_y<<endl;
	
	return 0;
} 
