//Íõ³Ì·É exp4_4
#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char toFind[100];
	char str[3][1000];
	int result[3]={0,0,0};
	int toFindLenth=0;
	int flag=0;
	int s_flag=0;
	
	gets(toFind);
	gets(str[0]);
	gets(str[1]);
	gets(str[2]);
	
	toFindLenth=strlen(toFind);
	
	
	for(int i=0;i<3;i++){
		flag=0;
		for(int j=0;j<strlen(str[i])-toFindLenth+1;j++){
			s_flag=0;
			for(int k=0;k<toFindLenth;k++){
				if(str[i][k+j]==toFind[k]){
					s_flag++;
				} 
				
				//cout<<str[i][k+j];
			}
			if(s_flag==toFindLenth){
				result[i]=1;
				break;
			}
			//cout<<s_flag<<endl;
		}
	}
	
	for(int i=0;i<3;i++){
		cout<<result[i]<<endl;
	}
	
	return 0;
} 
