#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include"friends.h"

using namespace std;

//�˵����� 
int menu()
{
	cout << endl;
	cout << "=======================У��¼����=======================" << endl;
	cout << "========================================================" << endl;
	cout << "|                ��ӭ����У��¼����ϵͳ                |" << endl;
	cout << "|                    1.¼��У����Ϣ                    |" << endl;
	cout << "|                    2.ɾ��У����Ϣ                    |" << endl;
	cout << "|                    3.����У����Ϣ                    |" << endl;
	cout << "|                    4.�޸�У����Ϣ                    |" << endl;
	cout << "|                    5.��ʾУ����Ϣ                    |" << endl;
	cout << "|                    0.�˳�                            |" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "---------------------��ѡ��0-5��:---------------------" << endl;
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






