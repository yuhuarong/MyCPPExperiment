#include<iostream>
#include<fstream> 
#include "Contract.cpp"
using namespace std;

/*
 * ��ͬ����ϵͳ 
 */
int printMenu(){
	cout<<"������Ҫʵ�ֵĹ��ܣ�"<<endl;
	cout<<"0 ��ȡ�µ��ļ�"<<endl;
	cout<<"1 ���Ӻ�ͬ"<<endl;
	cout<<"2 ɾ����ͬ"<<endl;
	cout<<"3 �޸ĺ�ͬ"<<endl;
	cout<<"4 ��ѯ��ͬ"<<endl;
	cout<<"5 �����ͬ"<<endl;
	cout<<"6 ���޸Ľ������"<<endl;
	cout<<"7 �˳�"<<endl;
	char code;
	cin>>code;
	switch(code){
		case '0':
			
			break;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			exit(0); 
			break;
		default: 
			cout<<"���������룺"<<endl;
			printMenu();
	} 
	
	return 0;
} 

int main() {
	fstream file;
	int hasFile=0;
	
	while(1){
		printMenu();
	}
	
	return 0;
}
