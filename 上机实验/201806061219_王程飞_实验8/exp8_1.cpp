#include<iostream>
#include<cstring>
using namespace std;

struct Student{
	char num[20],name[30];
	int score;
}; 

int main(){
	Student *s=new Student[3];
	Student t;
	for(int i=0;i<3;i++){
		cin>>s[i].num>>s[i].name>>s[i].score;
	}
	int m=0;
	for(int i=0;i<2;i++){
		m=i;
		for(int j=i;j<3;j++){
			if(strcmp(s[j].num,s[m].num)>0){
				m=j;
			}
		}
		if(m!=i){
			t=s[i];s[i]=s[m];s[m]=t;
		}
	}
	
	for(int i=0;i<3;i++){
		cout<<s[i].num<<" "<<s[i].name<<" "<<s[i].score<<endl;
	}
	
	
	return 0;
}
