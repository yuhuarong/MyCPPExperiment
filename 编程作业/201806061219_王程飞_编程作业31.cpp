#include<iostream>
using namespace std;

struct Student{
	char num[30];
	int score;
	
};

int fun(Student *s,Student *b,int start,int end,int n){
	int c=0;
	for(int i=0;i<n;i++){
		if(s[i].score<=end&&s[i].score>=start){
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
	
	cout<<"input start&end:"<<endl;
	cin>>start>>end;
	
	c=fun(s,b,start,end,n);
	
//	for(int i=0;i<c;i++){
//		cout<<b[i].num<<" "<<b[i].score<<endl;
//	}

	cout<<c<<endl;
	
	
	return 0;
}
