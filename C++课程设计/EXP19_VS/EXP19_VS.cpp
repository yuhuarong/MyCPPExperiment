#pragma once
#include<iostream>
#include<fstream> 
#include<string> 
#include<cstring>
#include "Contract.cpp"
#include "COntractUI.cpp"
#include<algorithm>
using namespace std;

bool compare(const ContractUI& a, const ContractUI& b) {
	if (a.signedDate.getYear() > b.signedDate.getYear()) {
		return false;
	}
	else if (a.signedDate.getYear() == b.signedDate.getYear()) {
		if (a.signedDate.getMonth() > b.signedDate.getMonth()) {
			return false;
		}
		else if (a.signedDate.getMonth() == b.signedDate.getMonth()) {
			if (a.signedDate.getDay() > b.signedDate.getDay()) {
				return false;
			}
			else if (a.signedDate.getDay() == b.signedDate.getDay()) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
}

/*
 * 合同管理系统
 */
char printMenu() {
	cout << "---菜单---" << endl;
	cout << "0 新打开读取文件" << endl;
	cout << "1 新打开写入文件" << endl;
	cout << "2 增加合同" << endl;
	cout << "3 删除合同" << endl;
	cout << "4 修改合同" << endl;
	cout << "5 查询合同" << endl;
	cout << "6 退出" << endl;
	cout << endl;
	cout << "请输入要实现的功能：";

	char code;
	cin >> code;
	return code;
}

int main() {

	char code;
	fstream file;
	char path[50] = "";

	Contract mContract;
	ContractUI mUI;

	//	Date nowDate;
	//	int yyyy,mm,dd;
	//	cout<<"输入当前日期(yyyy MM dd): ";
	//	nowDate.init();
	//	cout<<"当前日期: "<<nowDate<<endl<<endl;

	while (1) {
		code = printMenu();
		switch (code) {
		case '0':
			if (file) {
				file.close();
			}
			cout << "输入文件名: ";
			cin >> path;
			file.open(path, ios::in);
			if (file) {
				cout << "---文件打开成功---" << endl;
			}
			else {
				cout << "---文件打开失败---" << endl;
			}

			break;
		case '1':
			if (file) {
				file.close();
			}
			cout << "输入文件名: ";
			cin >> path;
			file.open(path, ios::app);
			if (file) {
				cout << "---文件打开成功---" << endl;
			}
			else {
				cout << "---文件打开失败---" << endl;
			}
			break;
		case '2':
			//增加合同
			if (file) {
				file.close();
			}
			if (strlen(path) > 0) {
				char confirm;
				cout << "目前打开的文件为 '" << path << "' 是否切换文件(y/n)?" << endl;
				cin >> confirm;
				switch (confirm) {
				case 'y':
				case 'Y':
					cout << "输入新文件名: ";
					cin >> path;
					break;
				default:
					cout << "---以写入方式打开文件 '" << path << "' ---" << endl;
				}
				file.open(path, ios::app);
			}
			else {
				cout << "没有打开的文件，输入文件名: ";
				cin >> path;
				file.open(path, ios::app);
			}

			if (file) {
				cout << "---文件打开成功---" << endl;
				cout << "输入合同信息:" << endl << endl;
				cin >> mUI;
				mContract = mUI;
				file << mContract;
				file.close();
				cout << "---文件写入成功---" << endl;
			}
			else {
				cout << "---文件打开失败---" << endl;
			}

			break;
		case '3':
			//删除合同 
			if (file) {
				file.close();
			}
			if (strlen(path) > 0) {
				char confirm;
				cout << "目前打开的文件为 '" << path << "' 是否切换文件(y/n)?" << endl;
				cin >> confirm;
				switch (confirm) {
				case 'y':
				case 'Y':
					cout << "输入新文件名: ";
					cin >> path;
					break;
				default:
					cout << "---打开文件 '" << path << "' ---" << endl;
				}
				file.open(path, ios::in);
			}
			else {
				cout << "没有打开的文件，输入文件名: ";
				cin >> path;
				file.open(path, ios::in);
			}

			if (file) {
				cout << "---文件打开成功---" << endl;
				cout << endl;
				Contract contracts[50];
				int t = 0;
				cout << "文件保存的合同如下: " << endl;
				cout << endl;
				while (file >> mContract) {
					contracts[t] = mContract;
					mUI = mContract;
					cout << mUI;
					t++;
				}
				int targetId;
				cout << endl;
				cout << "输入要删除的合同ID: ";
				cin >> targetId;
				file.close();
				file.open(path, ios::out);
				if (file) {
					for (int i = 0; i < t; i++) {
						if (contracts[i].id != targetId) {
							file << contracts[i];
						}
					}
					cout << "---删除成功---" << endl;
					file.close();
				}
				else {
					cout << "---删除失败---" << endl;
				}

			}
			else {
				cout << "---文件打开失败---" << endl;
			}

			break;
		case '4':
			//修改合同 
			if (file) {
				file.close();
			}
			if (strlen(path) > 0) {
				char confirm;
				cout << "目前打开的文件为 '" << path << "' 是否切换文件(y/n)?" << endl;
				cin >> confirm;
				switch (confirm) {
				case 'y':
				case 'Y':
					cout << "输入新文件名: ";
					cin >> path;
					break;
				default:
					cout << "---打开文件 '" << path << "' ---" << endl;
				}
				file.open(path, ios::in);
			}
			else {
				cout << "没有打开的文件，输入文件名: ";
				cin >> path;
				file.open(path, ios::in);
			}

			if (file) {
				cout << "---文件打开成功---" << endl;
				cout << endl;
				Contract contracts[50];
				int t = 0;
				cout << "文件保存的合同如下: " << endl;
				cout << endl;
				while (file >> mContract) {
					contracts[t] = mContract;
					mUI = mContract;
					cout << mUI;
					t++;
				}
				int targetId;
				cout << endl;
				cout << "输入要修改的合同ID: ";
				cin >> targetId;
				file.close();
				file.open(path, ios::out);
				if (file) {
					for (int i = 0; i < t; i++) {
						if (contracts[i].id == targetId) {
							char code;
							cout << "---找到目标合同---" << endl << endl;
							cout << "0 ID" << endl;
							cout << "1 甲方: " << endl;
							cout << "2 乙方: " << endl;
							cout << "3 内容: " << endl;
							cout << "4 开始时间: " << endl;
							cout << "5 结束时间: " << endl;
							cout << "6 金额: " << endl;
							cout << "7 签订日期: " << endl;
							cout << endl;
							cout << "请选择要修改的项目: ";
							while (cin >> code) {
								switch (code) {
								case '0':
									cout << "输入新的ID: ";
									cin >> contracts[i].id;
									break;
								case '1':
									cout << "输入新的甲方: ";
									cin >> contracts[i].partyA;
									break;
								case '2':
									cout << "输入新的乙方: ";
									cin >> contracts[i].partyB;
									break;
								case '3':
									cout << "输入新的内容: ";
									cin >> contracts[i].content;
									break;
								case '4':
									cout << "输入新的开始时间(yyyy MM dd): ";
									contracts[i].validStart.init();
									break;
								case '5':
									cout << "输入新的结束时间(yyyy MM dd): ";
									contracts[i].validEnd.init();
									break;
								case '6':
									cout << "输入新的金额: ";
									cin >> contracts[i].money;
									break;
								case '7':
									cout << "输入新的签订时间(yyyy MM dd): ";
									contracts[i].signedDate.init();
									break;
								default:
									code = 'n';
								}
								if (code != 'n') {
									break;
								}
								cout << "输入有误，请重新输入: ";
							}
						}
						file << contracts[i];
					}

					cout << "---修改结束---" << endl;
					file.close();
				}
				else {
					cout << "---修改失败---" << endl;
				}

			}
			else {
				cout << "---文件打开失败---" << endl;
			}
			break;
		case '5':
			//读取/查找合同
			if (file) {
				file.close();
			}
			if (strlen(path) > 0) {
				char confirm;
				cout << "目前打开的文件为 '" << path << "' 是否切换文件(y/n)?" << endl;
				cin >> confirm;
				switch (confirm) {
				case 'y':
				case 'Y':
					cout << "输入新文件名: ";
					cin >> path;
					break;
				default:
					cout << "---以读取方式打开文件 '" << path << "' ---" << endl;
				}
				file.open(path, ios::in);
			}
			else {
				cout << "没有打开的文件，输入文件名: ";
				cin >> path;
				file.open(path, ios::in);
			}

			if (file) {
				cout << "---文件打开成功---" << endl;
				cout << endl;
				cout << "---菜单---" << endl;
				cout << "0 输出全部合同" << endl;
				cout << "1 输出某一天的" << endl;
				cout << "2 输出到今天为止到期的" << endl;
				cout << "3 输出这个月签订的合同" << endl;
				cout << "4 根据甲方或乙方查询合同" << endl;
				cout << endl;
				cout << "选择输出条件: ";
				char inputCode;
				cin >> inputCode;
				//					int yyyy, MM, dd;
				Date nowDate;
				switch (inputCode) {
				case '1':
					cout << endl;
					cout << "输入要显示的合同的日期: ";
					Date targetDate;
					targetDate.init();
					cout << "文件保存的合同信息:" << endl << endl;
					while (file >> mContract) {
						if (mContract.signedDate == targetDate || mContract.validEnd == targetDate || mContract.validStart == targetDate) {
							mUI = mContract;
							cout << mUI;
						}
					}
					break;
				case '2':
					cout << endl;
					cout << "输入当前日期(yyyy MM dd): ";
					nowDate.init();
					cout << "文件保存的合同信息:" << endl << endl;
					while (file >> mContract) {
						if (mContract.validEnd < nowDate || mContract.validEnd == nowDate) {
							mUI = mContract;
							cout << mUI;
						}
					}
					break;
				case '3': {
					cout << "输入当前日期(yyyy MM dd): ";
					nowDate.init();
					ContractUI cUI[50];
					int sum = 0;
					cout << "文件保存的合同信息:" << endl << endl;
					while (file >> mContract) {
						if (mContract.signedDate.year == nowDate.year && mContract.signedDate.month == nowDate.month) {
							mUI = mContract;
							//									cout<<mUI; 
							cUI[sum] = mUI;
							sum++;
						}
					}
					cout << "一共有 " << sum << " 条记录" << endl;
					sort(cUI, cUI + sum, compare);
					for (int k = 0; k < sum; k++) {
						cout << cUI[k];
					}
					break;
				}

				case '4': {
					cout << "输入要查询的甲方或乙方：";
					string party;
					cin >> party;
					while (file >> mContract) {
						if (mContract.partyA.compare(party) == 0 || mContract.partyB.compare(party) == 0) {
							mUI = mContract;
							cout << mUI;
						}
					}
					break;
				}
				case '0':
				default: {
					ContractUI cUI[50];
					int sum = 0;
					cout << "文件保存的合同信息:" << endl << endl;
					while (file >> mContract) {
						mUI = mContract;
						//								cout<<mUI; 
						cUI[sum] = mUI;
						sum++;
					}
					cout << "一共有 " << sum << " 条记录" << endl;
					sort(cUI, cUI + sum, compare);
					for (int k = 0; k < sum; k++) {
						cout << cUI[k];
					}
					break;
				}
				}

				cout << endl << "输出完成" << endl;

				file.close();

			}
			else {
				cout << "---文件打开失败---" << endl;
			}

			break;
		case '6':
			if (file) {
				file.close();
			}
			exit(0);
			break;
		default:
			cout << "请重新输入：" << endl;
		}
		cout << endl;
	}

	return 0;
}
