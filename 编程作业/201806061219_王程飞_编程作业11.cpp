#include<iostream>
using namespace std;

int anal(char c)
{
	if(c>='A'&&c<='Z'){
		return 0;
	}else if(c>='a'&&c<='z'){
		return 1;
	}else if(c>='0'&&c<='9'){
		return 2;
	}else if(c==' '){
		return 3;
	}else{
		//cout<<(int)c<<endl;
		return 4;
	}
	
} 

int main()
{
	int num[5]={0,0,0,0,0};
	char a[1000];
	char b[1000];
	char c[1000];
	gets(a);
	gets(b);
	gets(c);
	
	for(int i=0;a[i]!='\0';i++){
		num[anal(a[i])]++;
	}
	for(int i=0;b[i]!='\0';i++){
		num[anal(b[i])]++;
	}
	for(int i=0;c[i]!='\0';i++){
		num[anal(c[i])]++;
	}
	
	cout<<"uppercase:"<<num[0]<<endl;
	cout<<"lowercase:"<<num[1]<<endl;
	cout<<"number:"<<num[2]<<endl;
	cout<<"blank:"<<num[3]<<endl;
	cout<<"other:"<<num[4]<<endl;
	
	return 0;
}
