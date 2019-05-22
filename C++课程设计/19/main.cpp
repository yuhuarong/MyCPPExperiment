#pragma once
#include<iostream>
#include<fstream> 
#include<string> 
#include<cstring>
#include "Contract.cpp"
#include "COntractUI.cpp"
#include<algorithm>
using namespace std;

bool compare(const ContractUI& a, const ContractUI& b){
	if(a.signedDate.getYear()>b.signedDate.getYear()){
		return false;
	} else if(a.signedDate.getYear()==b.signedDate.getYear()) {
		if(a.signedDate.getMonth()>b.signedDate.getMonth()){
			return false;
		} else if(a.signedDate.getMonth()==b.signedDate.getMonth()) {
			if(a.signedDate.getDay()>b.signedDate.getDay()){
				return false;
			} else if(a.signedDate.getDay()==b.signedDate.getDay()) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	} else {
		return true;
	}
} 

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
	cout<<"6 �˳�"<<endl;
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
	ContractUI mUI; 
	
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
					cin>>mUI;
					mContract=mUI;
					file<<mContract; 
					file.close();
					cout<<"---�ļ�д��ɹ�---"<<endl; 
				} else {
					cout<<"---�ļ���ʧ��---"<<endl;
				}
				
				break;
			case '3':
				//ɾ����ͬ 
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
							cout<<"---���ļ� '"<<path<<"' ---"<<endl;
					}
					file.open(path, ios::in);
				} else {
					cout<<"û�д򿪵��ļ��������ļ���: "; 
					cin>>path;
					file.open(path, ios::in);
				}

				if(file){
					cout<<"---�ļ��򿪳ɹ�---"<<endl;
					cout<<endl;
					Contract contracts[50];
					int t=0;
					cout<<"�ļ�����ĺ�ͬ����: "<<endl;
					cout<<endl;
					while(file>>mContract) {
						contracts[t]=mContract;
						mUI=mContract;
						cout<<mUI; 
						t++;
					}
					int targetId;
					cout<<endl; 
					cout<<"����Ҫɾ���ĺ�ͬID: ";
					cin>>targetId;
					file.close(); 
					file.open(path, ios::out);
					if(file){
						for(int i=0;i<t;i++){
							if(contracts[i].id!=targetId){
								file<<contracts[i];
							}
						}
						cout<<"---ɾ���ɹ�---"<<endl;
						file.close(); 
					} else {
						cout<<"---ɾ��ʧ��---"<<endl;
					}
					
				} else {
					cout<<"---�ļ���ʧ��---"<<endl;
				}
				
				break;
			case '4':
				//�޸ĺ�ͬ 
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
							cout<<"---���ļ� '"<<path<<"' ---"<<endl;
					}
					file.open(path, ios::in);
				} else {
					cout<<"û�д򿪵��ļ��������ļ���: "; 
					cin>>path;
					file.open(path, ios::in);
				}

				if(file){
					cout<<"---�ļ��򿪳ɹ�---"<<endl;
					cout<<endl;
					Contract contracts[50];
					int t=0;
					cout<<"�ļ�����ĺ�ͬ����: "<<endl;
					cout<<endl;
					while(file>>mContract) {
						contracts[t]=mContract;
						mUI=mContract;
						cout<<mUI; 
						t++;
					}
					int targetId;
					cout<<endl; 
					cout<<"����Ҫ�޸ĵĺ�ͬID: ";
					cin>>targetId;
					file.close();
					file.open(path, ios::out);
					if(file){
						for(int i=0;i<t;i++){
							if(contracts[i].id==targetId){
								char code;
								cout<<"---�ҵ�Ŀ���ͬ---"<<endl<<endl;
								cout<<"0 ID"<<endl;
								cout<<"1 �׷�: "<<endl;
								cout<<"2 �ҷ�: "<<endl;
								cout<<"3 ����: "<<endl;
								cout<<"4 ��ʼʱ��: "<<endl;
								cout<<"5 ����ʱ��: "<<endl;
								cout<<"6 ���: "<<endl;
								cout<<"7 ǩ������: "<<endl;
								cout<<endl;
								cout<<"��ѡ��Ҫ�޸ĵ���Ŀ: "; 
								while(cin>>code){
									switch(code){
										case '0':
											cout<<"�����µ�ID: ";
											cin>>contracts[i].id;
											break;
										case '1':
											cout<<"�����µļ׷�: ";
											cin>>contracts[i].partyA;
											break;
										case '2':
											cout<<"�����µ��ҷ�: ";
											cin>>contracts[i].partyB;
											break;
										case '3':
											cout<<"�����µ�����: ";
											cin>>contracts[i].content;
											break;
										case '4':
											cout<<"�����µĿ�ʼʱ��(yyyy MM dd): ";
											contracts[i].validStart.init();
											break;
										case '5':
											cout<<"�����µĽ���ʱ��(yyyy MM dd): ";
											contracts[i].validEnd.init();
											break;
										case '6':
											cout<<"�����µĽ��: ";
											cin>>contracts[i].money;
											break;
										case '7':
											cout<<"�����µ�ǩ��ʱ��(yyyy MM dd): ";
											contracts[i].signedDate.init();
											break;
										default:
											code='n';
									}
									if(code!='n'){
										break;
									}
									cout<<"������������������: ";
								}
							}
							file<<contracts[i];
						}
						
						cout<<"---�޸Ľ���---"<<endl;
						file.close(); 
					} else {
						cout<<"---�޸�ʧ��---"<<endl;
					}
					
				} else {
					cout<<"---�ļ���ʧ��---"<<endl;
				}
				break;
			case '5':
				//��ȡ/���Һ�ͬ
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
							cout<<"---�Զ�ȡ��ʽ���ļ� '"<<path<<"' ---"<<endl;
					}
					file.open(path, ios::in);
				} else {
					cout<<"û�д򿪵��ļ��������ļ���: "; 
					cin>>path;
					file.open(path, ios::in);
				}

				if(file){
					cout<<"---�ļ��򿪳ɹ�---"<<endl;
					cout<<endl;
					cout<<"---�˵�---"<<endl;
					cout<<"0 ���ȫ����ͬ"<<endl;
					cout<<"1 ���ĳһ���"<<endl;
					cout<<"2 ���������Ϊֹ���ڵ�"<<endl;
					cout<<"3 ��������ǩ���ĺ�ͬ"<<endl;
					cout<<"4 ���ݼ׷����ҷ���ѯ��ͬ"<<endl; 
					cout<<endl; 
					cout<<"ѡ���������: ";
					char inputCode;
					cin>>inputCode; 
//					int yyyy, MM, dd;
					Date nowDate;
					switch(inputCode){
						case '1':
							cout<<endl; 
							cout<<"����Ҫ��ʾ�ĺ�ͬ������: ";
							Date targetDate;
							targetDate.init();
							cout<<"�ļ�����ĺ�ͬ��Ϣ:"<<endl<<endl;
							while(file>>mContract) {
								if(mContract.signedDate==targetDate||mContract.validEnd==targetDate||mContract.validStart==targetDate){
									mUI=mContract;
									cout<<mUI; 
								}
							}
							break;
						case '2':
							cout<<endl;
							cout<<"���뵱ǰ����(yyyy MM dd): ";
							nowDate.init();
							cout<<"�ļ�����ĺ�ͬ��Ϣ:"<<endl<<endl;
							while(file>>mContract) {
								if(mContract.validEnd<nowDate||mContract.validEnd==nowDate){
									mUI=mContract;
									cout<<mUI; 
								}
							}
							break;
						case '3':{
							cout<<"���뵱ǰ����(yyyy MM dd): ";
							nowDate.init();
							ContractUI cUI[50];
							int sum=0; 
							cout<<"�ļ�����ĺ�ͬ��Ϣ:"<<endl<<endl;
							while(file>>mContract) {
								if(mContract.signedDate.year==nowDate.year&&mContract.signedDate.month==nowDate.month){
									mUI=mContract;
//									cout<<mUI; 
									cUI[sum]=mUI;
									sum++;
								}
							}
							cout<<"һ���� "<<sum<<" ����¼"<<endl; 
							sort(cUI, cUI+sum, compare);
							for(int k=0; k<sum; k++){
								cout<<cUI[k];
							} 
							break;
						}
							
						case '4':{
							cout<<"����Ҫ��ѯ�ļ׷����ҷ���";
							string party;
							cin>>party;
							while(file>>mContract) {
								if(mContract.partyA.compare(party)==0||mContract.partyB.compare(party)==0){
									mUI=mContract;
									cout<<mUI; 
								}
							}
							break; 
						}
						case '0':
						default:{
							ContractUI cUI[50];
							int sum=0; 
							cout<<"�ļ�����ĺ�ͬ��Ϣ:"<<endl<<endl;
							while(file>>mContract) {
								mUI=mContract;
//								cout<<mUI; 
								cUI[sum]=mUI;
								sum++;
							}
							cout<<"һ���� "<<sum<<" ����¼"<<endl; 
							sort(cUI, cUI+sum, compare);
							for(int k=0; k<sum; k++){
								cout<<cUI[k];
							} 
							break;
						}
					} 
					
					cout<<endl<<"������"<<endl; 
					
					file.close(); 
					
				} else {
					cout<<"---�ļ���ʧ��---"<<endl;
				}
				
				break;
			case '6':
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
