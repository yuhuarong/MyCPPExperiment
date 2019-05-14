#include<iostream>
#include<fstream> 
#include "Contract.cpp"
using namespace std;

/*
 * 合同管理系统 
 */
int printMenu(){
	cout<<"请输入要实现的功能："<<endl;
	cout<<"0 读取新的文件"<<endl;
	cout<<"1 增加合同"<<endl;
	cout<<"2 删除合同"<<endl;
	cout<<"3 修改合同"<<endl;
	cout<<"4 查询合同"<<endl;
	cout<<"5 输出合同"<<endl;
	cout<<"6 将修改结果保存"<<endl;
	cout<<"7 退出"<<endl;
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
			cout<<"请重新输入："<<endl;
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
