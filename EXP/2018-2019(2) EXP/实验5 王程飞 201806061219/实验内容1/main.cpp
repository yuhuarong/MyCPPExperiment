#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return a>b;
} 

int main(){
	int a[10]={56,34,3,67,89,55,22,43,12,9};
	sort(a, a+10, cmp);
	ofstream outfile("data.txt", ios::out);
	if(outfile){
		cout<<"write successed"<<endl;
		for(int i=0;i<9;i++){
			outfile<<a[i]<<",";
		}
		outfile<<a[9]<<endl;
		outfile.close();
	}

	ifstream in;
	char c[100];
	in.open("data.txt", ios::in);
	if(in){
		in>>c;
		cout<<c;
		in.close();
	}
} 
