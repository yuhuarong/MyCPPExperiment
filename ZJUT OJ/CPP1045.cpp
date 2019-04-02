#include<iostream>
#include<cstring>
using namespace std;

int str_cmp(char *a,char *b,int n){
	for(int i=0;i<n;i++){
		
		if(a[i]>b[i]){
			return 1;
		}else if(a[i]<b[i]){
			return -1; 
		}
		//cout<<"*"<<i<<" "<<a[i]<<" "<<b[i]<<endl;
	}
	return 0;
}

int cmp(char *a,char * b){
	int i=0;
	if(str_cmp(a+6,b+6,4)!=0){
		i = str_cmp(a+6,b+6,4);
		//cout<<a+6<<b+6<<endl;
	}else{
		if(str_cmp(a+3,b+3,2)!=0){
			i = str_cmp(a+3,b+3,2);
		}else{
			if(str_cmp(a,b,2)!=0){
				i = str_cmp(a,b,2);
			}else{
				i = 0;
			}
		}
	}
	//cout<<i<<endl;
	return i;
}

int main(){
	int y[1000],m[1000],d[1000];
	int i=0,min;
	char t,a[1000][20];
	while(cin>>a[i]){
		i++;
	}
	for(int j=0;j<i;j++){
		min=j;
		for(int k=j+1;k<i;k++){
			if(cmp(a[min],a[k])>0) min=k;
		}
		char tmp[20];
		strcpy(tmp,a[j]);
		strcpy(a[j],a[min]);
		strcpy(a[min],tmp);
	}
	for(int j=0;j<i;j++){
		cout<<a[j]<<endl;
	}
}
