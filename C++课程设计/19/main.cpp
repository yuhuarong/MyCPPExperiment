#include<iostream>
#include<fstream> 
#include<string> 
#include<cstring>
#include "Contract.cpp"
using namespace std;

/*
 * ��ͬ����ϵͳ 
 */
char printMenu(){
	cout<<"---�˵�---"<<endl; 
	cout<<"0 �´򿪶�ȡ�ļ�"<<endl;
	cout<<"1 �´�д���ļ�"<<endl;
	cout<<"2 ���Ӻ�ͬ"<<endl;
	cout<<"3 ɾ����ͬ"<<endl;
	cout<<"4 �޸ĺ�ͬ"<<endl;
	cout<<"5 ��ѯ��ͬ"<<endl;
	cout<<"6 �����ͬ"<<endl;
	cout<<"7 �˳�"<<endl;
	cout<<endl;
	cout<<"������Ҫʵ�ֵĹ��ܣ�";

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
//	cout<<"���뵱ǰ����(yyyy MM dd): ";
//	nowDate.init();
//	cout<<"��ǰ����: "<<nowDate<<endl<<endl;
	
	while(1){
		code = printMenu();
		switch(code){
			case '0':
				if(file){
					file.close();
				} 
				cout<<"�����ļ���: "; 
				cin>>path;
				file.open(path, ios::in);
				if(file){
					cout<<"---�ļ��򿪳ɹ�---"<<endl; 
				} else {
					cout<<"---�ļ���ʧ��---"<<endl; 
				}

				break;
			case '1':
				if(file){
					file.close();
				} 
				cout<<"�����ļ���: "; 
				cin>>path;
				file.open(path, ios::app);
				if(file){
					cout<<"---�ļ��򿪳ɹ�---"<<endl; 
				} else {
					cout<<"---�ļ���ʧ��---"<<endl; 
				}
				break;
			case '2':
				//���Ӻ�ͬ
				if(file){
					file.close(); 
				} 
				if(strlen(path)>0){
					char confirm;
					cout<<"Ŀǰ�򿪵��ļ�Ϊ '"<<path<<"' �Ƿ��л��ļ�(y/n)?"<<endl;
					cin>>confirm;
					switch(confirm){
						case 'y':
						case 'Y':
							cout<<"�������ļ���: ";
							cin>>path; 
							break;
						default:
							cout<<"---��д�뷽ʽ���ļ� '"<<path<<"' ---"<<endl;
					}
					file.open(path, ios::app);
				} else {
					cout<<"û�д򿪵��ļ��������ļ���: "; 
					cin>>path;
					file.open(path, ios::app);
				}

				if(file){
					cout<<"---�ļ��򿪳ɹ�---"<<endl; 
					cout<<"�����ͬ��Ϣ:"<<endl<<endl;
					cin>>mContract;
					file<<mContract; 
					
				} else {
					cout<<"---�ļ���ʧ��---"<<endl;
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
				cout<<"���������룺"<<endl;
		} 
		cout<<endl; 
	}
	
	return 0;
}
