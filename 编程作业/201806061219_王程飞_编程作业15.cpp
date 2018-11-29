#include <iostream>
using namespace std;

int main(){
	int n,a[100];
	cin>>n;
	int cursor=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[(j-cursor)<0?(cursor-j):(j-cursor)];
		}
		cout<<endl;
		cursor++;
	}
	
	return 0;
}
