#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include"friends.h"

using namespace std;

//菜单函数 
int menu()
{
	cout << endl;
	cout << "=======================校友录管理=======================" << endl;
	cout << "========================================================" << endl;
	cout << "|                欢迎进入校友录管理系统                |" << endl;
	cout << "|                    1.录入校友信息                    |" << endl;
	cout << "|                    2.删除校友信息                    |" << endl;
	cout << "|                    3.查找校友信息                    |" << endl;
	cout << "|                    4.修改校友信息                    |" << endl;
	cout << "|                    5.显示校友信息                    |" << endl;
	cout << "|                    0.退出                            |" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "---------------------请选择（0-5）:---------------------" << endl;
	return 0;
}
int main()
{
	fdp f;
	int c;
	menu();
	cin >> c;
	if (c <= 5)
	{
		switch (c)
		{
		case 1:f.add(); cout << endl << endl; main(); break;
		case 2:f.deleted(); cout << endl << endl; main(); break;
		case 3:f.alter(); cout << endl << endl; main(); break;
		case 4:f.find(); cout << endl << endl; main(); break;
		case 5:f.show(); cout << endl << endl; main(); break;
		case 0:exit(1); break;
		}
	}
	else { cout << setw(35) << "input error!!!" << endl; main(); }
}






