#include<iostream>
using namespace std;

int ct(char *p){
	int i;
	for(i=0;*p!='\0';p++,i++);
	return i;
}

int main(){
	char a[100];
	cin>>a;
	cout<<ct(a);
	
	return 0;
} 
