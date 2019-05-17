#include<iostream>
#include<fstream> 
#include<string> 
#include<cstring>
#include "Contract.cpp"
using namespace std;

/*
 * 合同管理系统 
 */
char printMenu(){
	cout<<"---菜单---"<<endl; 
	cout<<"0 新打开读取文件"<<endl;
	cout<<"1 新打开写入文件"<<endl;
	cout<<"2 增加合同"<<endl;
	cout<<"3 删除合同"<<endl;
	cout<<"4 修改合同"<<endl;
	cout<<"5 查询合同"<<endl;
	cout<<"6 输出合同"<<endl;
	cout<<"7 退出"<<endl;
	cout<<endl;
	cout<<"请输入要实现的功能：";

	char code;
	cin>>code; 
	return code;
} 

int main() {
	
	char code;
	fstream file;
	char path[50]="";
	
	Contract mContract; 
	
//	Date nowDate;
//	int yyyy,mm,dd;
//	cout<<"输入当前日期(yyyy MM dd): ";
//	nowDate.init();
//	cout<<"当前日期: "<<nowDate<<endl<<endl;
	
	while(1){
		code = printMenu();
		switch(code){
			case '0':
				if(file){
					file.close();
				} 
				cout<<"输入文件名: "; 
				cin>>path;
				file.open(path, ios::in);
				if(file){
					cout<<"---文件打开成功---"<<endl; 
				} else {
					cout<<"---文件打开失败---"<<endl; 
				}

				break;
			case '1':
				if(file){
					file.close();
				} 
				cout<<"输入文件名: "; 
				cin>>path;
				file.open(path, ios::app);
				if(file){
					cout<<"---文件打开成功---"<<endl; 
				} else {
					cout<<"---文件打开失败---"<<endl; 
				}
				break;
			case '2':
				//增加合同
				if(file){
					file.close(); 
				} 
				if(strlen(path)>0){
					char confirm;
					cout<<"目前打开的文件为 '"<<path<<"' 是否切换文件(y/n)?"<<endl;
					cin>>confirm;
					switch(confirm){
						case 'y':
						case 'Y':
							cout<<"输入新文件名: ";
							cin>>path; 
							break;
						default:
							cout<<"---以写入方式打开文件 '"<<path<<"' ---"<<endl;
					}
					file.open(path, ios::app);
				} else {
					cout<<"没有打开的文件，输入文件名: "; 
					cin>>path;
					file.open(path, ios::app);
				}

				if(file){
					cout<<"---文件打开成功---"<<endl; 
					cout<<"输入合同信息:"<<endl<<endl;
					cin>>mContract;
					file<<mContract; 
					
				} else {
					cout<<"---文件打开失败---"<<endl;
				}
				
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
				if(file){
					file.close();
				} 
				exit(0); 
				break;
			default: 
				cout<<"请重新输入："<<endl;
		} 
		cout<<endl; 
	}
	
	return 0;
}
