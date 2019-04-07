#include<iostream>
#include<cstring>
using namespace std;

struct Person{
	char num[30];
	char name[100];
	float score;
}person[5];

int main(){
	float sum=0;int max=0;
	for(int i=0;i<5;i++){
		cin>>person[i].num>>person[i].name>>person[i].score;
		sum+=person[i].score;max=(person[i].score>person[max].score)?i:max;
	}
	cout<<person[max].num<<" "<<person[max].name<<" "<<person[max].score<<" "<<sum/5<<endl;
	
	return 0;
}
