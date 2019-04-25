#include<iostream>
#include<fstream>
using namespace std;

int main(){
	cout<<"helloworld"<<endl;
//	ofstream outfile("f1.dat", ios::out);
//	int a[10];
//	
//	for(int i=0;i<10;i++){
//		cin>>a[i];
//		//cout<<a[i]<<" ";
//		outfile<<a[i]<<endl;
//	}
//	cout<<endl;
//	outfile.close();

	ifstream in;
	int b[10],max;
	
	in.open("f1.dat", ios::in);
	for(int i=0;i<10;i++){
		in>>b[i];
		cout<<b[i]<<endl;
	}
	
	in.close();
//	if(outfile){
//		cout<<"successed"<<endl;
//		outfile<<"Helloworld"<<endl;
//		outfile.close();
//	}
} 
