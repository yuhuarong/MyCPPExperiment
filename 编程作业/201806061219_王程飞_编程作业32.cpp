#include<iostream>
using namespace std;

struct Student{
	char num[30];
	int score;
	
};

int fun(Student *s,Student *b,int n){
	int c=0,sum=0;float avg=0;
	for(int i=0;i<n;i++){
		sum+=s[i].score;
	}
	
	avg=sum/n;
	
	for(int i=0;i<n;i++){
		if(s[i].score>avg){
			b[c++]=s[i];
		}
	}
	
	return c;
	
}

int main(){
	Student s[100],b[100];
	int c,n,start,end;
	
	cout<<"input n:"<<endl;
	cin>>n;
	
	cout<<"input item:"<<endl;
	for(int i=0;i<n;i++){
		cin>>s[i].num>>s[i].score;
	}
	
	c=fun(s,b,n);

	cout<<c<<endl;
	
	
	return 0;
}
