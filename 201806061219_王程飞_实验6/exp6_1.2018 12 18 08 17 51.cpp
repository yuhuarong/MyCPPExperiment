#include<iostream>
#include<cstring>
using namespace std;

void c_sort(char a[5][100]){
	int m;char t[100];
	for(int i=0;i<4;i++){
		m=4-i;
		for(int j=0;j<4-i;j++){
			if(strcmp(a[m],a[j])>0){
				m=j;
			}
		}
		if(m!=i){
			strcpy(t,a[i]);strcpy(a[i],a[m]);strcpy(a[m],t);
		}
	}
}

int main(){
	char a[5][100];
	for(int i=0;i<5;i++){
		cin>>a[i];
	} 
	
	c_sort(a);
	for(int i=0;i<5;i++){
		cout<<a[i]<<endl;
	}
	
	
	return 0; 
} 
