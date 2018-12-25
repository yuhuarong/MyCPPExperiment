//Íõ³Ì·É exp4_1
#include <iostream>
using namespace std;

int main(){
	int m,n;
	int a[100][100];
	int sumClum[100];
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sumClum[i]+=a[j][i];
			
		}
		cout<<sumClum[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}


